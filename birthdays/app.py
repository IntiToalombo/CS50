from cs50 import SQL
from flask import Flask, redirect, render_template, request
import calendar

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

# Function to validate day based on month
def is_valid_day(month, day):
    try:
        month = int(month)
        day = int(day)

        # Check if the months is between 1-12
        if month < 1 or month > 12:
            return False
        # Get the max days in the month
        max_days = calendar.monthrange(2024, month)[1]
        return 1 <= day <= max_days
    except ValueError:
        return False

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"]) # Decoretor for extended the functionality of some basic function
def index():

    errors = {} # To store error messages
    if request.method == "POST":

        # Get data
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Validation of input data
        if not name:
            errors["name"] = "Name is required"
        elif not month or not day:
            errors["date"] = "Both Month and Day are required"
        elif not is_valid_day(month,day):
            errors["date"] = f"Invalid day for the selected month (Month: {month})"

        # If there are not errors, insert data in database
        if not errors:
            db.execute("INSERT INTO birthdays(name, month, day) VALUES(?, ?, ?)", name, month, day)
            return redirect("/")

    # Render the form with errors (if any and pre-filled values)
    rows =  db.execute("SELECT * FROM birthdays")
    return render_template("index.html", errors=errors, birthdays=rows)


@app.route("/delete/<int:id>")
def delete(id):
    # Delete a birthday
    db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")
@app.route("/modify/<int:id>", methods=["GET", "POST"])

def modify(id):
    errors={}

    # Retrieve the birthday entry by ID for the GET request
    birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)

    if len(birthday) == 0:
        return render_template("error.html", message="Birthday not found")
    if request.method == "POST":
        # Update the birthday entry in the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

         # Validation of input data
        if not name:
            errors["name"] = "Name is required"
        elif not month or not day:
            errors["date"] = "Both Month and Day are required"
        elif not is_valid_day(month,day):
            errors["date"] = f"Invalid day for the selected month (Month: {month})"

        if not errors:
            db.execute("UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?",name, month, day, id)
            return redirect("/")


    # Render the modify template with birthday data and errors (if any)
    return render_template("modify.html", birthday=birthday[0], errors=errors)




# get text from user
def get_text(prompt):
    text = input(prompt)
    return text

# compute number of letters


def count_letters(text):
    number_letters = 0
    spaces = 0
    for i in text:
        if not i.isalpha():
            spaces += 1
    number_letters = len(text) - spaces
    return number_letters

# compute number of words


def count_words(text):
    number_words = 0
    for i in text:
        if i == " ":
            number_words += 1
    return number_words + 1

# compute number of sentences


def count_sentences(text):
    number_sentences = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            number_sentences += 1
    return number_sentences

# Apply Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8.


def grade(text):
    L = (count_letters(text) / count_words(text)) * 100
    S = (count_sentences(text) / count_words(text)) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)
    if 1 < grade < 16:
        return f"Grade {grade}"
    if grade >= 16:
        return f"Grade 16+"
    if grade < 1:
        return f"Before Grade 1"


def main():
    txt = get_text("Enter the text: ")
    '''
    letters = count_letters(txt)
    words = count_words(txt)
    sentences = count_sentences(txt)
    print(f"Letters: {letters}, Words: {words}, Sentences: {sentences}")
    '''
    result = grade(txt)
    print(result)

    
if __name__ == "__main__":
    main()

-- Keep a log of any SQL queries you execute as you solve the mystery.

.tables
-- To check available tables to begin the investigation
.schema crime_scene_reports
-- I check the table's schema and the data that contains crime_scene_reports
SELECT * FROM crime_scene_reports WHERE month = '7' AND year = '2023' AND day = '28' AND street = 'Humphrey Street'
-- I found that crime took place at ---10:15---
-- All witnesses mentioned the      ---Bakery---
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted
-- today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
SELECT * FROM interviews WHERE year = '2023'AND month = '7' AND day = '28' AND transcript LIKE '%bakery%';
                    --| Ruth    |
                    --  Time Frame : 10:05 - 10: 25, exiting from the bakery
--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot
--and drive away. If you have security footage from the bakery parking lot, you might want to look for
-- cars that left the parking lot in that time frame.
                                                      |
                    --| Eugene  |
                    --  ATM, Leggett Street, withdraw
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived
-- at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
                                                                                              |
                    --| Raymond |
                    -- Call duration: < 1 min, flight(earliest) July 29, 2023
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville
--tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

SELECT * FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND minute > 4 AND minute < 26 AND activity = 'exit';
/*
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+-----+------+-------+-----+------+--------+----------+---------------+
*/
SELECT * FROM atm_transactions WHERE year = '2023' AND month ='7' AND day = '28' AND atm_location = 'Leggett Street' and transaction_type = 'withdraw';

/*
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
*/
SELECT * FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration < 60 ;
/*
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+
*/
SELECT * FROM flights WHERE year = '2023' AND month='7' AND day='29' ORDER BY hour, minute LIMIT 1;
/*
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+
*/
SELECT person_id
FROM bank_accounts
WHERE account_number IN(
SELECT account_number
FROM atm_transactions
WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
-- I got ids of person whom were in Leggett Street on July 28, 2023 withdrawing money
/*
+-----------+
| person_id |
+-----------+
| 686048    |
| 514354    |
| 458378    |
| 395717    |
| 396669    |
| 467400    |
| 449774    |
| 438727    |
+-----------+
*/

--SELECT name FROM people WHERE id IN(SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE atm_location='Leggett Street' AND transaction_type = 'withdraw'AND year='2023' AND month='7' AND day ='28')) AND license_plate IN(SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day='28' AND hour = 10 AND minute > 4 AND minute < 26 AND activity = 'exit') AND passport_number IN(SELECT passport_number FROM passengers );
SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
        AND year = '2023'
        AND month = '7'
        AND day = '28'
    )
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = '2023'
    AND month = '7'
    AND day = '28'
    AND hour = 10
    AND minute > 4
    AND minute < 26
    AND activity = 'exit'
)
AND passport_number IN (
    SELECT passport_number
    FROM passengers
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = '2023'
    AND month = '7'
    AND day = '28'
    AND duration < 60
);


 -- I got a list of suspects
/*
+-------+
| name  |
+-------+
| Diana |
| Bruce |
+-------+
*/
SELECT full_name FROM airports WHERE id IN(SELECT destination_airport_id FROM flights WHERE year = '2023' AND month = '7' AND day ='29' ORDER BY hour, minute LIMIT 1);
/*
+-------------------+
|     full_name     |
+-------------------+
| LaGuardia Airport |
+-------------------+
*/
---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
-- FROM THE 1ST WITNESS
SELECT people.name, bakery_security_logs.license_plate
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = '2023'
  AND bakery_security_logs.day = '28'
  AND bakery_security_logs.hour = '10'
  AND bakery_security_logs.minute > 4
  AND bakery_security_logs.minute < 26
  AND bakery_security_logs.activity = 'exit';
/*
+---------+---------------+
|  name   | license_plate |
+---------+---------------+
| Vanessa | 5P2BI95       |
| Bruce   | 94KL13X       |
| Barry   | 6P58WS2       |
| Luca    | 4328GD8       |
| Sofia   | G412CB7       |
| Iman    | L93JTIZ       |
| Diana   | 322W7JE       |
| Kelsey  | 0NTHK55       |
+---------+---------------+
*/
-- FROM THE 2ND WITNESS
SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = '2023'
          AND month = '7'
          AND day = '28'
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
    )
);
/*
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
+---------+
*/
-- FROM 3RD WITNESS
SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = '2023'
      AND month = '7'
      AND day = '28'
      AND duration < 60
);
/*
+---------+
|  name   |
+---------+
| Kenny   |
| Sofia   |
| Benista |
| Taylor  |
| Diana   |
| Kelsey  |
| Bruce   |
| Carina  |
+---------+
*/
LIST of SUSPECTS
+---------+  
|  name   |
+---------+
| Vanessa |
| Barry   |
| Iman    |
| Sofia   |
| Luca    |
| Diana   |
| Kelsey  |
| Bruce   |
+---------+

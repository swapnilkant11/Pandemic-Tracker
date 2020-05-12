# Pandemic-Tracker Documentation

A pandemic tracker using OOPS concept in C++ using data structures and algorithms.

## My assumptions while designing this system are:-

1. Used a single simple user defined map data structure as local database to store the reported cases.
2. Used indexing as slNodb variable in map to uniquely identify the stored reports of the patients, it plays a role of primary key in the database.
3. Assumed that the PATIENT ID is unique in a given city but may vary for different cities.
4. Assumed the three different case of a patient during reporting of a case by the user, I have created three different cases for reporting a case which are,
   one where user can report a ACTIVE CASE, second where a user can report a CURED CASE and third where a user can report a FATALITY CASE.
5. Assumed an extra field called 'Patient_State' in the given form of test case which states the situation of the patient whether the case is ACTIVE, CURED
   or it's a case of FATALITY.
6. Assumed that more than one case can be reported for a given state, city and country.

## Input format:

The test cases will be taken in the following format.

1. Choose which case to report be it ACTIVE, CURE or FATALITY by giving number 1, 2 or 3 as the input else enter 0 to exit.
2. Next, enter the DISEASE, PATIENT ID, COUNTRY, STATE and CITY of the patient.
3. Next,enter 1 if you want to report more cases else enter 0 to exit.

Database updated with all records given by the user, Now you can view them too!! Follow the steps below:-

1. Enter 5 to view the complete database of patient.
2. Enter 6 to view world summary disease breakup.
3. Enter 7 to view country breakup.
4. Enter 8 to view state breakup.
5. Enter 9 9 to view the world summary.

Now, if you entered 7 enter the name of disease you wish to see the result.
if entered 8 enter the disease and country for which yoou wish to view state breakup result.

### Example:

#### Sample Input:

```
1
COVID-19
P1
China
Hubei
Wuhan
1
2
Spanish Flu
P9
USA
California
Los Angeles
0
5

```
#### Sample Output:

We have selected 5 so the output will be:

```
COVID-19 P1 China Hubei Wuhan
Spanish Flu” P9 USA California Los Angeles

```
Similarly users can test other functions as well to explore the different fucntions of the system as stated above.

## Time Complexity:

1. The time complexity of the system is searching in time O(1) because of map used.
2. The time complexity for insertion to the database O(1) with unique ID for each record.

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Student Management System - C++</title>
</head>
<body>

<h1>📘 Student Management System (C++)</h1>

<p>
This project is a <strong>console-based Student Management System</strong> written in C++.
It allows users to store, retrieve, update, delete, and display student records using
<strong>file handling</strong>.
</p>

<hr>

<h2>🧩 Features</h2>
<ul>
    <li>Enroll new students</li>
    <li>Avoid duplicate roll numbers</li>
    <li>Search students by roll number</li>
    <li>Update student details</li>
    <li>Delete student records</li>
    <li>Display all enrolled students</li>
    <li>Persistent data storage using text files</li>
</ul>

<hr>

<h2>🗂 Data Structure Used</h2>

<h3>Student Structure</h3>
<pre>
struct Student {
    int roll;
    string name;
    string branch;
    int sem;
};
</pre>

<p>
The <code>Student</code> structure groups all student-related data into a single unit.
This makes file operations and data handling cleaner and more organized.
</p>

<hr>

<h2>📜 File Used</h2>
<ul>
    <li><strong>students.txt</strong> → Stores all student records permanently</li>
    <li><strong>temp.txt</strong> → Temporary file used during update, delete, and search operations</li>
</ul>

<hr>

<h2>📋 Function Explanations</h2>

<h3>1️⃣ menu()</h3>
<p>
Displays the main menu options for the user.
This improves readability and provides a user-friendly interface.
</p>

<hr>

<h3>2️⃣ rollExists(int roll)</h3>
<p>
Checks whether a roll number already exists in <code>students.txt</code>.
</p>

<ul>
    <li>Prevents duplicate student enrollment</li>
    <li>Reads records one by one from the file</li>
    <li>Returns <code>true</code> if roll exists, otherwise <code>false</code></li>
</ul>

<hr>

<h3>3️⃣ enrollStudent()</h3>
<p>
Adds a new student record to the file.
</p>

<ul>
    <li>Takes input for roll, name, branch, and semester</li>
    <li>Validates input using <code>cin.fail()</code></li>
    <li>Uses <code>rollExists()</code> to prevent duplicate roll numbers</li>
    <li>Appends data to <code>students.txt</code></li>
</ul>

<hr>

<h3>4️⃣ searchStudent()</h3>
<p>
Searches for a student using roll number.
</p>

<ul>
    <li>Reads from <code>students.txt</code></li>
    <li>Displays student data if found</li>
    <li>Uses a temporary file to safely rewrite data</li>
</ul>

<hr>

<h3>5️⃣ updateStudent()</h3>
<p>
Updates an existing student's information.
</p>

<ul>
    <li>Searches by roll number</li>
    <li>Allows updating roll, name, branch, and semester</li>
    <li>Uses file replacement technique (temp file)</li>
</ul>

<hr>

<h3>6️⃣ displayStudent()</h3>
<p>
Displays all enrolled students in a tabular format.
</p>

<ul>
    <li>Reads all records from file</li>
    <li>Prints formatted output to console</li>
</ul>

<hr>

<h3>7️⃣ deleteStudent()</h3>
<p>
Deletes a student record based on roll number.
</p>

<ul>
    <li>Asks for confirmation before deletion</li>
    <li>Rewrites file excluding the selected student</li>
</ul>

<hr>

<h3>8️⃣ main()</h3>
<p>
Controls the entire application flow.
</p>

<ul>
    <li>Uses a <code>do-while</code> loop to keep program running</li>
    <li>Uses <code>switch-case</code> for menu navigation</li>
    <li>Handles invalid input gracefully</li>
    <li>Cleans garbage entries (roll = 0)</li>
</ul>

<hr>

<h2>🧠 Key Concepts Used</h2>
<ul>
    <li>Structures (<code>struct</code>)</li>
    <li>File Handling (<code>ifstream</code>, <code>ofstream</code>)</li>
    <li>Input Validation (<code>cin.fail()</code>)</li>
    <li>Temporary File Technique</li>
    <li>Switch-Case Control Flow</li>
    <li>Looping (<code>do-while</code>)</li>
    <li>Data Persistence</li>
</ul>

<hr>

<h2>🚀 Future Improvements</h2>
<ul>
    <li>Use <strong>CSV or JSON</strong> format instead of plain text</li>
    <li>Add <strong>password-based authentication</strong></li>
    <li>Replace text files with a <strong>database (SQLite / MySQL)</strong></li>
    <li>Allow <strong>full names with spaces</strong> using <code>getline()</code></li>
    <li>Improve UI using colors or GUI (Qt / SFML)</li>
    <li>Implement sorting by roll, name, or semester</li>
    <li>Use <strong>classes and OOP principles</strong></li>
    <li>Add logging and backup functionality</li>
</ul>

<hr>

<h2>📌 Conclusion</h2>
<p>
This project demonstrates strong fundamentals of C++ programming, especially
<strong>file handling, input validation, and structured data management</strong>.
It is an excellent base for expanding into advanced systems or database-driven applications.
</p>

<p><strong>Author:</strong> Akshay</p>

</body>
</html>

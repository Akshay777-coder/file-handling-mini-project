<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Student Management System - C++</title>
</head>
<body>

<h1>📘 Student Management System (C++)</h1>

<div class="section">
<h2>🔧 How to Compile and Run the Program (Windows)</h2>

<h3>1. Install GCC Compiler</h3>
<p>
Install <b>MinGW-w64</b> or <b>MSYS2</b> and add the <code>bin</code> directory to your system PATH.
</p>

<p>Verify installation:</p>
<pre>g++ --version</pre>

<h3>2. Save the File</h3>
<p>Save the source code as:</p>
<pre>student_management.cpp</pre>

<h3>3. Compile the Code</h3>
<pre>g++ student_management.cpp -o student_management</pre>

<h3>4. Run the Program</h3>
<pre>student_management</pre>
</div>

<div class="section">
<h2>📌 Project Overview</h2>
<p>
This project is a <b>file-based Student Management System</b> written in C++.
It allows users to:
</p>
<ul>
    <li>Enroll students</li>
    <li>Search student records</li>
    <li>Update student information</li>
    <li>Display all students</li>
    <li>Delete student records</li>
</ul>
<p>
All records are stored persistently in a text file (<code>students.txt</code>).
</p>
</div>

<div class="section">
<h2>📂 Header Files Used</h2>
<ul>
    <li><code>&lt;iostream&gt;</code> – Input & output operations</li>
    <li><code>&lt;fstream&gt;</code> – File handling</li>
    <li><code>&lt;limits&gt;</code> – Input validation using stream limits</li>
</ul>
</div>

<div class="section">
<h2>🧱 Structure: Student</h2>
<pre>
struct Student {
    int roll;
    string name;
    string branch;
    int sem;
};
</pre>
<p>
The <b>Student</b> structure stores all student-related data as a single unit.
</p>
</div>

<div class="section">
<h2>📋 menu() Function</h2>
<p>
Displays the available operations to the user.
</p>
<ul>
    <li>Enroll Student</li>
    <li>Search Student</li>
    <li>Update Student</li>
    <li>Display Students</li>
    <li>Delete Student</li>
    <li>Exit</li>
</ul>
</div>

<div class="section">
<h2>🔍 rollExists(int roll)</h2>
<p>
Checks whether a roll number already exists in <code>students.txt</code>.
</p>
<p>
<b>Purpose:</b> Prevent duplicate roll numbers during enrollment.
</p>
<ul>
    <li>Reads file using <code>ifstream</code></li>
    <li>Returns <b>true</b> if roll is found</li>
    <li>Returns <b>false</b> if file does not exist or roll is not found</li>
</ul>
</div>

<div class="section">
<h2>➕ enrollStudent()</h2>
<p>
Adds a new student record to the file.
</p>
<ul>
    <li>Validates numeric input using <code>cin.fail()</code></li>
    <li>Checks duplicate roll numbers</li>
    <li>Appends data to the file</li>
</ul>
<p>
If invalid input is detected, input buffer is cleared and enrollment is cancelled.
</p>
</div>

<div class="section">
<h2>🔎 searchStudent()</h2>
<p>
Searches for a student by roll number.
</p>
<ul>
    <li>Reads data from file</li>
    <li>Displays student if found</li>
    <li>Uses a temporary file for safe rewriting</li>
</ul>
</div>

<div class="section">
<h2>✏️ updateStudent()</h2>
<p>
Updates the details of an existing student.
</p>
<ul>
    <li>Asks for old roll number</li>
    <li>Allows updating all student fields</li>
    <li>Uses temporary file method</li>
</ul>
</div>

<div class="section">
<h2>📊 displayStudent()</h2>
<p>
Displays all students in tabular format.
</p>
<ul>
    <li>Reads all records from file</li>
    <li>Prints formatted output</li>
</ul>
</div>

<div class="section">
<h2>🗑️ deleteStudent()</h2>
<p>
Deletes a student record using roll number.
</p>
<ul>
    <li>Asks for confirmation (<code>'y'</code>)</li>
    <li>Skips the record to be deleted</li>
    <li>Uses temp file replacement technique</li>
</ul>
</div>

<div class="section">
<h2>🧠 Error Handling</h2>
<ul>
    <li><code>cin.fail()</code> detects invalid input</li>
    <li><code>cin.clear()</code> resets input stream</li>
    <li><code>cin.ignore()</code> clears garbage input</li>
    <li>File open failure is handled safely</li>
</ul>
</div>

<div class="section">
<h2>🔄 Main Function</h2>
<p>
Controls the program using a <b>do-while loop</b> and <b>switch-case</b>.
</p>
<ul>
    <li>Calls appropriate functions based on user choice</li>
    <li>Handles invalid input gracefully</li>
    <li>Cleans corrupted records (roll = 0)</li>
</ul>
</div>

<div class="section">
<h2>🔑 Key Concepts Used</h2>
<ul>
    <li>Structures</li>
    <li>File Handling</li>
    <li>Input Validation</li>
    <li>Switch Case</li>
    <li>Functions</li>
    <li>Temporary File Replacement</li>
    <li>Error Handling</li>
</ul>
</div>

<div class="section">
<h2>🚀 Possible Future Improvements</h2>
<ul>
    <li>Use binary files</li>
    <li>Add password authentication</li>
    <li>Use vectors instead of files</li>
    <li>Improve UI formatting</li>
    <li>Add search by name or branch</li>
</ul>
</div>

</body>
</html>

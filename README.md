<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Student Management System (C++)</title>
</head>
<body>

<h1>📚 Student Management System (C++)</h1>

<p>
This project is a <strong>console-based Student Management System</strong> written in C++.
It uses <strong>file handling</strong> to permanently store student records and allows
the user to perform common CRUD operations:
</p>

<ul>
    <li>Enroll a new student</li>
    <li>Search a student</li>
    <li>Update student details</li>
    <li>Display all students</li>
    <li>Delete a student</li>
</ul>

<hr>

<h2>📂 Data Storage</h2>

<p>
Student data is stored in a text file named <code>students.txt</code>.
Each student record is stored in the following format:
</p>

<pre>
Roll Name Branch Semester
</pre>

<p>
Example:
</p>

<pre>
101 Akshay CSE 3
102 Rahul ECE 2
</pre>

<hr>

<h2>🧱 Structure Definition</h2>

<pre>
struct Student{
    int roll;
    string name;
    string branch;
    int sem;
};
</pre>

<p>
This structure groups all student-related data into a single unit.
</p>

<ul>
    <li><strong>roll</strong> → Unique roll number</li>
    <li><strong>name</strong> → Student name</li>
    <li><strong>branch</strong> → Department/Branch</li>
    <li><strong>sem</strong> → Current semester</li>
</ul>

<hr>

<h2>📋 Menu Function</h2>

<pre>
void menu()
</pre>

<p>
Displays the available operations to the user.
This function is called repeatedly inside the main loop.
</p>

<hr>

<h2>🔍 rollExists(int roll)</h2>

<p>
Checks whether a roll number already exists in the file.
This prevents duplicate student enrollments.
</p>

<h3>Key Concepts Used:</h3>
<ul>
    <li>File reading using <code>ifstream</code></li>
    <li>Sequential search in file</li>
    <li>Duplicate validation</li>
</ul>

<p>
Returns:
</p>
<ul>
    <li><code>true</code> → Roll number already exists</li>
    <li><code>false</code> → Roll number is unique</li>
</ul>

<hr>

<h2>➕ enrollStudent()</h2>

<p>
Enrolls a new student into the system.
</p>

<h3>Steps:</h3>
<ol>
    <li>Accept roll number</li>
    <li>Validate numeric input</li>
    <li>Check for duplicate roll using <code>rollExists()</code></li>
    <li>Accept name, branch, and semester</li>
    <li>Store data in <code>students.txt</code></li>
</ol>

<h3>Key Concepts:</h3>
<ul>
    <li>File append mode (<code>ios::app</code>)</li>
    <li>Input validation using <code>cin.fail()</code></li>
    <li>Permanent data storage</li>
</ul>

<hr>

<h2>🔎 searchStudent()</h2>

<p>
Searches a student using roll number and displays details if found.
</p>

<h3>How It Works:</h3>
<ul>
    <li>Reads data from <code>students.txt</code></li>
    <li>Compares each roll with input roll</li>
    <li>Displays student if found</li>
    <li>Uses a temporary file to safely rewrite data</li>
</ul>

<h3>Important Concept:</h3>
<p>
File updating is done using a <strong>temporary file strategy</strong>
because text files cannot be edited directly.
</p>

<hr>

<h2>✏️ updateStudent()</h2>

<p>
Updates an existing student's details.
</p>

<h3>Steps:</h3>
<ol>
    <li>Ask for previous roll number</li>
    <li>Search the student in file</li>
    <li>Accept new details</li>
    <li>Write updated record to temporary file</li>
    <li>Replace original file</li>
</ol>

<h3>Concepts Used:</h3>
<ul>
    <li>File replacement using <code>remove()</code> and <code>rename()</code></li>
    <li>Conditional record update</li>
</ul>

<hr>

<h2>📊 displayStudent()</h2>

<p>
Displays all students in a tabular format.
</p>

<h3>Features:</h3>
<ul>
    <li>Reads entire file</li>
    <li>Displays data neatly</li>
    <li>Preserves file integrity</li>
</ul>

<hr>

<h2>🧠 Input Validation</h2>

<p>
The program prevents invalid inputs using:
</p>

<pre>
cin.fail()
cin.clear()
cin.ignore(numeric_limits&lt;streamsize&gt;::max(), '\n');
</pre>

<p>
This ensures:
</p>
<ul>
    <li>No crashes due to wrong input</li>
    <li>Clean program execution</li>
</ul>

<hr>

<h2>🗑️ Garbage Record Cleanup</h2>

<p>
If invalid input accidentally creates a record with roll number <code>0</code>,
the program automatically removes it.
</p>

<p>
This cleanup logic runs after every menu operation.
</p>

<hr>

<h2>🔁 Main Function</h2>

<pre>
int main()
</pre>

<p>
Controls the program flow using a <code>do-while</code> loop and <code>switch-case</code>.
</p>

<h3>Responsibilities:</h3>
<ul>
    <li>Display menu</li>
    <li>Handle user choice</li>
    <li>Call appropriate functions</li>
    <li>Exit safely</li>
</ul>

<hr>

<h2>🚀 Key Concepts Used</h2>

<ul>
    <li>Structures in C++</li>
    <li>File handling (ifstream / ofstream)</li>
    <li>Temporary file technique</li>
    <li>Input validation</li>
    <li>Switch-case control flow</li>
    <li>Loop-based menu system</li>
</ul>

<hr>

<h2>✅ Conclusion</h2>

<p>
This project is an excellent example of:
</p>

<ul>
    <li>Beginner-friendly file handling</li>
    <li>Real-world CRUD application</li>
    <li>Safe and structured C++ programming</li>
</ul>

<p>
It can be further enhanced by:
</p>

<ul>
    <li>Using binary files</li>
    <li>Adding authentication</li>
    <li>Using vectors instead of text files</li>
</ul>

<p><strong>Happy Coding! 🚀</strong></p>

</body>
</html>

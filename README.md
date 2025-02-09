🎭 SixDegreesOfActors 🎬
========================

🔍 **Find the shortest path between two actors based on shared movie appearances!**

📌 Overview
-----------

Ever wondered how closely connected actors are in Hollywood? **SixDegreesOfActors** is a graph-based program that analyzes a dataset of movies and actors to determine the shortest path between two given actors. Inspired by the "Six Degrees of Kevin Bacon" concept, this tool constructs an actor-movie graph and efficiently finds relationships between actors using **Breadth-First Search (BFS)**.

🚀 Features
-----------

✅ Parses **massive datasets** of movies and actors 📁\
✅ **Finds shortest paths** between actors via shared films 🎬\
✅ Optimized **BFS algorithm** for fast lookup 🔎\
✅ **Handles missing data** and disconnected actors gracefully 🚫\
✅ Customizable for **any movie-actor dataset** 🎥

* * * * *

🔍 How It Works
---------------

1️⃣ **Parses a dataset** where each line represents a movie and its cast.\
2️⃣ **Builds a graph**, where actors are nodes, and movies create edges between them.\
3️⃣ **Processes queries**, finding the shortest path between two actors.\
4️⃣ **Outputs results**, formatting paths as:

`<ACTOR1> -(<MOVIE>)- <NEXT ACTOR> -(<MOVIE>)- <NEXT ACTOR>...`

5️⃣ If no path exists, it outputs **"Not present"**.

* * * * *

📥 Example Input & Output
-------------------------

### 📝 Input File: `simple-input.txt`

Each line contains two actor names:

`Seshadhri John_Wayne`  
`Ingrid_Bergman Ingrid_Bergman`

### 📄 Output File: `simple-output.txt`

`Not present`  
`Ingrid_Bergman`

Explanation:

-   "Seshadhri" and "John Wayne" are not found in the dataset.
-   "Ingrid Bergman" is the same actor, so it prints their name directly.

* * * * *

🛠 Installation & Usage
-----------------------

### 📥 1. Clone the Repository

`git clone https://github.com/your-username/SixDegreesOfActors.git`  
`cd SixDegreesOfActors`

### 🏗 2. Build the Program

`make`

This compiles the code and generates an executable named `sixdegrees`.

### ▶️ 3. Run the Program

`./sixdegrees input.txt output.txt`

-   `input.txt` → File containing actor queries
-   `output.txt` → File where results will be stored

🔹 Replace `input.txt` with your own dataset formatted similarly.

* * * * *

📂 File Structure
-----------------

- 📂 SixDegreesOfActors
- ├── 📄 Makefile          # Automates compilation
- ├── 📄 sixdegrees.cpp    # Core program logic
- ├── 📄 graph.h           # Graph & BFS implementation
- ├── 📄 input.txt         # Sample queries
- ├── 📄 output.txt        # Sample results
- ├── 📄 README.md         # This file`

* * * * *

🎯 Algorithm Overview
---------------------

1️⃣ **Parse Movie Dataset** 🎬\
2️⃣ **Build Graph Representation** (Adjacency List)\
3️⃣ **Run BFS for Shortest Path** 🔍\
4️⃣ **Format & Output Results**

* * * * *

🚀 Performance & Constraints
----------------------------

⚡ **Optimized Execution:**

-   Handles **100,000+ movies** and actors efficiently.
-   **BFS ensures shortest path computation in O(V + E)**.

📌 **Edge Cases Handled:**

-   If either actor **does not exist**, return `"Not present"`.
-   If no connection exists, return `"Not present"`.
-   If both actors are the same, return the actor's name.

* * * * *

🔥 Future Improvements
----------------------

🔹 Optimize storage using **hash maps** for faster lookups.\
🔹 Implement **weighted edges** for actor connection strengths.\
🔹 Expand dataset beyond IMDB snapshots.

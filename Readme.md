# Spatiotemporal Trajectory Analysis

Spatiotemporal Trajectory Analysis is a system designed for processing PIR (Passive Infrared Detector) sensor data, aiming to reconstruct human behavior trajectories and behavioral semantics in indoor scenarios. It mainly consists of three functional modules:

- **Data Import Module**: Provides input, management, and visualization of vector data and sensor data
- **Sensor Trajectory Reconstruction Module**: Implements sensor network topology generation and motion trajectory reconstruction
- **Sensor Semantic Analysis Module**: Achieves behavioral semantic extraction under temporal and spatial window constraints

Software Environment Requirements:

- Operating System: Microsoft Windows 7 or above
- Development Framework: WxWidgets 3.0.0, CAUSTA and SAGA
- Runtime Environment: WxWidgets 3.0.X and above version support libraries
- Database: POSTGRESQL (for storing PIR sensor response data)
- Development Tools: Visual Studio 2013

Project Structure

```
Spatiotemporal Trajectory Analysis/
├── data.sql/                    # POSTGRESQL data files
└── Spatiotemporal Trajectory Analysis Demo/ # Project directory
    ├── res/                     # Resource files
    ├── mathplot/                # Visualization files
    ├── floorplanshp/            # 3D scene data files
    └── ...                      # Code and project files
└── README.md                    # This file
```

## Code and Descriptions Corresponding to the Five Steps

### 1. Representation

Corresponds to encoding raw geospatial data and domain knowledge, mapping them into representations within a mathematical space.

-   **trajectory_analysis_module.cpp**: Defines module input parameters (`SensorData`, `Floor`, `SensorPoint`). These parameters correspond to raw geospatial data (sensor data, floor information, sensor locations) and are the abstract representation of geospatial data at the representation layer.
-   **trajctory_analysis_scalculate.cpp (Constructor)**: Initializes the sensor node list (sensor IDs in `m_comboBox1`) and database connection information, mapping physical sensor entities in geographic space into processable node data; reads neighborhood relationships (top, bottom, left, right node IDs) from the `linyu` table, encoding geographic topology knowledge into structured node relationships.
-   **trajctory_analysis_tcalculate.cpp (Constructor)**: Builds the node topology structure (`LNode` contains top, bottom, left, right node IDs) by querying the `linyu` table in the database, transforming geographic topology knowledge into node association data in the mathematical space.

### 2. Reasoning

Corresponds to the reasoning process using GA operators within the mathematical space, deriving relationships or states based on existing data and rules.

-   **`Update_Semantics` function in trajctory_analysis_scalculate.cpp**: Queries sensor activation data before and after a specific node (`selectID`) within a time window (`Pres` for preceding data, `Ares` for subsequent data), combines it with neighborhood relationships from the `linyu` table, and infers the node's preceding and subsequent state queues (`preque`, `aftque`). This is a logical reasoning process based on spatiotemporal relationships.
-   **`Set_Semantics` function in trajctory_analysis_scalculate.cpp**: Infers semantic codes (e.g., `eU-eC` for "enter", `eC-eU` for "leave") based on the size and direction (`direction`) of `preque` and `aftque`. This is a rule-based semantic reasoning process.

### 3. Generation

Corresponds to generating new structures (such as trajectories, semantic matrices) within the mathematical space.

-   **`ComputePath` function in trajctory_analysis_tcalculate.cpp**: Generates a trajectory list (`trajectList`) and final trajectory results (`traResult`) based on sensor activation data (`res`) and node topology (`tNode`). This involves the generation of trajectory structures.
-   **`DrawMatrix` function in trajctory_analysis_scalculate.cpp**: Generates binary matrices (`a` and `b` matrices) from time-series sensor activation data and visualizes them as bitmaps (`wxBitmap`). This involves the generation of data matrices.

### 4. Synthesis

Corresponds to validating the generated structures against constraints to ensure they conform to rules or topological relationships.

-   **`ComputePath` function in trajctory_analysis_tcalculate.cpp**: Uses the `ifexist` function to check for duplicate nodes and the `isAdjacent` function to verify node adjacency, ensuring the generated trajectory complies with topological constraints; uses time window constraints (e.g., `30*1000` milliseconds) to ensure the temporal reasonableness of the trajectory. This constitutes validation of the generated trajectory.
-   Implicit validation of database query results (e.g., checking the number of results with `PQntuples`): Ensures the validity of input data, preventing empty or erroneous data from participating in calculations. This belongs to data-level validation.

### 5. Computing

Corresponds to converting expressions from the mathematical space into executable workflows, performing computations, and mapping the results back to geographic space.

-   **Database operations in trajctory_analysis_tcalculate.cpp and trajctory_analysis_scalculate.cpp**: Execute SQL queries via `Query`, `QueryTraj` functions to obtain sensor data required for calculations (e.g., time and node IDs from the `fireday` table). This belongs to data acquisition at the computing layer.
-   **Specific computational logic in `ComputePath` and `DrawMatrix`**: For example, trajectory traversal and node relationship calculation in `ComputePath`, matrix assignment and drawing operations in `DrawMatrix`. These represent the actual execution of computations.
-   **Interactive components in trajectory_analysis_dialog.cpp**: The "Start" button on the toolbar (`m_toolbar`), and the "Trajectory Computation"/"Semantic Computation" options in the menu (`m_Traj`, `m_Sem`) trigger the computation workflow, converting mathematical operations into an executable workflow. This belongs to scheduling at the computing layer.

In summary, the five parts of the GA model are implemented through the functions and logic in the aforementioned `.cpp` files. The core revolves around encoding geospatial data, applying reasoning rules, generating structures, validating constraints, and executing computations.
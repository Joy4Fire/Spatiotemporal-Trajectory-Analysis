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
└── Spatiotemporal Trajectory Analysis Demo/                   # Project directory
    ├── res/                     # Resource files
    ├── mathplot/                # Visualization files
    ├── floorplanshp/            # 3D scene data files
    └── ...                      # Code and project files
└── README.md                    # This file
```

## 五个步骤对应的代码和说明

### 1. 表达（Representation）  
对应地理空间原始数据与领域知识的编码，将其映射为数学空间的表示形式。  
- **trajectory_analysis_module.cpp**：定义模块输入参数（`SensorData`、`Floor`、`SensorPoint`），这些参数对应地理空间的原始数据（传感器数据、楼层信息、传感器位置），是表达层对地理空间数据的抽象表示。  
- **trajctory_analysis_scalculate.cpp（构造函数）**：初始化传感器节点列表（`m_comboBox1`中的传感器ID）、数据库连接信息，将地理空间的传感器实体映射为可处理的节点数据；读取`linyu`表中的邻域关系（上下左右节点ID），将地理拓扑知识编码为结构化的节点关系。  
- **trajctory_analysis_tcalculate.cpp（构造函数）**：通过数据库查询`linyu`表，构建节点拓扑结构（`LNode`包含上下左右节点ID），将地理空间的拓扑知识转化为数学空间的节点关联数据。  


### 2. 推理（Reasoning）  
对应数学空间中GA算子的推理过程，基于已有数据和规则推导关系或状态。  
- **trajctory_analysis_scalculate.cpp中的`Update_Semantics`函数**：根据时间窗口查询某节点（`selectID`）前后的传感器激活数据（`Pres`为前序数据，`Ares`为后序数据），结合`linyu`表的邻域关系，推理出节点的前后状态队列（`preque`、`aftque`），属于基于时空关系的逻辑推理。  
- **trajctory_analysis_scalculate.cpp中的`Set_Semantics`函数**：根据`preque`和`aftque`的大小、方向（`direction`），推理出语义编码（如`eU-eC`表示“进入”，`eC-eU`表示“离开”），是基于规则的语义推理过程。  


### 3. 生成（Generation）  
对应数学空间中生成新的结构（如轨迹、语义矩阵等）。  
- **trajctory_analysis_tcalculate.cpp中的`ComputePath`函数**：基于传感器激活数据（`res`）和节点拓扑（`tNode`），生成轨迹列表（`trajectList`）和最终轨迹结果（`traResult`），属于轨迹结构的生成。  
- **trajctory_analysis_scalculate.cpp中的`DrawMatrix`函数**：根据时间序列的传感器激活数据，生成二进制矩阵（`a`和`b`矩阵），并将其可视化为位图（`wxBitmap`），属于数据矩阵的生成。  


### 4. 校验（Synthesis）  
对应对生成的结构进行约束验证，确保符合规则或拓扑关系。  
- **trajctory_analysis_tcalculate.cpp中的`ComputePath`函数**：通过`ifexist`函数检查节点是否重复，`isAdjacent`函数验证节点是否相邻，确保生成的轨迹符合拓扑约束；通过时间窗口（如`30*1000`毫秒）限制，确保轨迹的时间合理性，属于对生成轨迹的校验。  
- 代码中隐含的数据库查询结果校验（如`PQntuples`检查查询结果数量）：确保输入数据的有效性，避免空数据或错误数据参与计算，属于数据层面的校验。  


### 5. 计算（Computing）  
对应将数学空间的表达式转换为可执行工作流，执行计算并映射回地理空间。  
- **trajctory_analysis_tcalculate.cpp和trajctory_analysis_scalculate.cpp中的数据库操作**：通过`Query`、`QueryTraj`函数执行SQL查询，获取计算所需的传感器数据（如`fireday`表的时间和节点ID），属于计算层的数据获取。  
- **`ComputePath`和`DrawMatrix`中的具体计算逻辑**：如`ComputePath`中的轨迹遍历与节点关系计算，`DrawMatrix`中的矩阵赋值与绘图操作，属于实际的计算执行。  
- **trajectory_analysis_dialog.cpp中的交互组件**：工具栏（`m_toolbar`）的“Start”按钮、菜单（`m_Traj`、`m_Sem`）的“Trajectory Computation”“Semantic Computation”选项，触发计算流程，将数学空间的操作转换为可执行工作流，属于计算层的调度。  


综上，GA模型的五个部分均通过上述`.cpp`文件中的函数和逻辑实现，核心围绕地理空间数据的编码、推理规则的应用、结构生成、约束校验及计算执行展开。
# Exploration Robot
This file contains the steps required to run the developed code for single and multi robot simulation, as well as for the real world implementation. This project was developed in the scope of Cognitive Robotics at Universidade de Coimbra by André Teixeira and João Jorge.

## Required Packages and Setup
Before running the simulations, the following packages need to be installed:
- navigation stack
- gmapping
- octomap_mapping

To install them run the following command in a terminal window
```
sudo apt install ros-noetic-navigation ros-noetic-gmapping ros-noetic-octomap ros-noetic-octomap-mapping ros-noetic-octomap-msgs ros-noetic-octomap-ros ros-noetic-octomap-rviz-plugins ros-noetic-octomap-server
```
The Gazebo simulator also needs to be installed.

After installing everything, change the current directory to your ROS workspace (usually **catkin_ws**) and run the following command in a terminal window
```
catkin_make
```
NOTE: You should remove any packages with same name from your ROS workspace before running the commands above

## Single Robot Gazebo Simulation 

To start the simulation, run the following command in a terminal window

```
roslaunch rc_explorer explore_gazebo_sim.launch
``` 


## Uncoordinated Multi Robot Stage Simulation
To start the simulation, run the following command in a terminal window

```
roslaunch rc_explorer explore_3robot_stage.launch
```

## Coordinated Multi Robot Stage Simulation
To start the simulation, run the following command in a terminal window

```
roslaunch simulator multirobot.launch
```
NOTE: Before running the command, change the <span style="color:orange">path_to_arena</span> parameter in the **multirobot.launch** file (line 27) to your path to arena. It should be something like this

```
<arg name="path_to_arena" default="/home/your_username/your_ws/src/rc_project/arena"/>
```

## Real World Implementation

To start the robot's operation, run the following command in a terminal window

```
roslaunch rc_explorer explore_real.launch
```

**WARNING:** The robot will start exploring immediately, with almost zero delay

NOTE: To stop the robot any key, EXCEPT the **'g'** key, can be pressed. To resume operation the **'g'** can be pressed. In both cases, the terminal window in which the above command was ran should be selected and highlighted


## Save generated map
To save the map generated during execution, run the following command in a terminal window (the map will be saved in the current directory)
```
rosrun map_server map_saver -f mymap
```
where **mymap** is the desired map name.

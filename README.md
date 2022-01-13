# Exploration Robot
This file contains the steps required to run the developed code for single and multi robot simulation, as well as for the physical real life implementation. This project was developed in the scope of Cognitive Robotics at Universidade de Coimbra by André Teixeira and João Jorge.

## Single Robot Gazebo Simulation 

To start the Gazebo simulation, run the following command in a terminal window

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

## Physical Implementation

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

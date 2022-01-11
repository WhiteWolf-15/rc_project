#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

sensor_msgs::LaserScan scan_filtered;
float maxRange = 6.0;

void scanFilterCallback(const sensor_msgs::LaserScanPtr& msg)
{
    scan_filtered.header = msg->header;
    scan_filtered.angle_min = msg->angle_min;
    scan_filtered.angle_max = msg->angle_max;
    scan_filtered.angle_increment = msg->angle_increment;
    scan_filtered.time_increment = msg->time_increment;
    scan_filtered.scan_time = msg->scan_time;
    scan_filtered.range_max = msg->range_max;
    scan_filtered.range_min = msg->range_min;
    scan_filtered.intensities = msg->intensities;
    
    for(int i = 0; i < msg->ranges.size(); i++){
        if(std::isnan(msg->ranges[i])){
            scan_filtered.ranges[i] = maxRange;
        }
        else{
            scan_filtered.ranges[i] = msg->ranges[i];
        }
    }
}

int main(int argc, char **argv){
	ros::init(argc, argv, "scan_filter_node");
	ros::NodeHandle nh;

    ros::Subscriber sub_scan_filter = nh.subscribe("/scan", 1, scanFilterCallback);
    ros::Publisher pub_scan_filter = nh.advertise<sensor_msgs::LaserScan>("scan_filtered", 10);

	ros::Rate rate(10);
	while(ros::ok()){
		rate.sleep();
        pub_scan_filter.publish(scan_filtered);
		ros::spinOnce();
	}
}
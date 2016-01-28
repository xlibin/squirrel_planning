#ifndef KCL_ROSPLAN_VIEWCONEGENERATOR_H
#define KCL_ROSPLAN_VIEWCONEGENERATOR_H

#include <vector>
#include <string>
#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <nav_msgs/OccupancyGrid.h>

namespace KCL_rosplan {

	class ViewConeGenerator {
	public:
		/**
		 * Constructor.
		 * @param node_handle A ROS node handle.
		 * @param topic_name The topic name on which the occupancy grid is published.
		 */
		ViewConeGenerator(ros::NodeHandle& node_handle, const std::string& topic_name);
		
		/**
		 * Callback function of the occupancy grid subscriber. It saves the latest received occupancy 
		 * grid message. This is used for collision detection.
		 * @param msg A pointer to the occupancy grid.
		 */
		void storeNavigationGrid(const nav_msgs::OccupancyGrid::ConstPtr& msg);
		
		/**
		 * Create a set of viewcones that covers the entire navigation grid.
		 * @param max_view_cones The maximum number of view cones that are generated.
		 * @param occupancy_threshold The threshold at which a point in the grid is considered occupied. The
		 * accepted range is [0,100].
		 * @param fov Field of view.
		 * @param view_distance The maximum viewing distance (straight in front).
		 * @param sample_size How many view cones should be generated at each iteration.
		 * @return The set of poses that observe (most of) the occupancy grid.
		 */
		std::vector<geometry_msgs::Pose> createViewCones(unsigned int max_view_cones, int occupancy_threshold, float fov, float view_distance, unsigned int sample_size);
	private:
		
		/**
		 * Check if two waypoints can be connected without colliding with any known scenery. The line is assumed
		 * to have an effective width of 0.
		 * @param w1 The first waypoint.
		 * @param w2 The second waypoint.
		 * @param occupancy_threshold The threshold at which a point in the grid is considered occupied. The
		 * accepted range is [0,100].
		 * @return True if the waypoints can be connected, false otherwise.
		 */
		bool canConnect(const geometry_msgs::Point& w1, const geometry_msgs::Point& w2, int occupancy_threshold);
		
		/**
		* Check if the area around @ref{point} is free, the radiance of the circle is @ref{min_distance}.
		* @param Point The centre of the circle to check.
		* @param min_distance The radiance of the circle.
		* @return True if this point is within @ref{min_distance} of an obstacle, false otherwise.
		*/
		bool isBlocked(const geometry_msgs::Point& point, float min_distance) const;
		
		ros::Subscriber navigation_grid_sub_;
		nav_msgs::OccupancyGrid last_received_occupancy_grid_msgs_;
		bool has_received_occupancy_grid_;
	};
};

#endif

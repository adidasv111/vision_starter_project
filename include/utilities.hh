#ifndef __VISION_UTILITIES_HH__
#define __VISION_UTILITIES_HH__

#include <pcl/visualization/pcl_visualizer.h>

/// @brief Visualize the PCLVisualizer for a period of time. If wait is negative, stop until keyboard is pressed. If wait is zero, skip visualizing, otherwise visualize to wait in ms.
void pcl_visualizer_show(pcl::visualization::PCLVisualizer& viewer, int wait = 500)
{
  // if negative, wait forever
  if (wait < 0)
  {
    viewer.spin();
  }
  else if (wait == 0)
  {
  }
  else
  {
    viewer.spinOnce();
    usleep(1000*wait);
  }
}

/// @brief initialize the PCLVisualizer object
pcl::visualization::PCLVisualizer init_visualizer(std::string window_name = "pcl_viewer")
{
  pcl::visualization::PCLVisualizer viewer(window_name);
  viewer.setBackgroundColor (0, 0, 0);
  viewer.addCoordinateSystem();

  viewer.setSize(1700,800);

  // from real camera angle
  viewer.setCameraPosition(-0.16,-1.8,-3.5,0.01,-0.92,0.37);
  // from top
  // viewer.setCameraPosition(0.0,-4.13,1.2,0.03,-0.06,0.997);

  // viewer->addCoordinateSystem (1.0);
  // viewer->initCameraParameters ();
  // viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "ransac cloud"); // set point size for cloud with given name

  return viewer;
}

#endif  // __VISION_UTILITIES_HH__

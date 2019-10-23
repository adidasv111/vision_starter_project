#include "header.hh"
#include "utilities.hh"

#include <string>

#include <sstream>
#include <iomanip>

#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

typedef pcl::PointXYZRGB PointT;

using namespace std;

int main(int argc, char *argv[])
{
  //prepare visualizer
  pcl::visualization::PCLVisualizer viewer = init_visualizer();

  std::string foldername = ""; // TODO add path
  if (argc > 1)
  {
    foldername = argv[1];
  }

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in_ptr(new pcl::PointCloud<PointT>);
  std::string filename;

  for (int i = 1;; i++)
  {
    cout << i << endl;
    std::stringstream ss;
    ss << std::setw(3) << std::setfill('0') << i;
    std::string s = ss.str();
    filename = foldername + s + ".pcd";
    int read = pcl::io::loadPCDFile(filename, *cloud_in_ptr);
    if (read < 0)
      return 0;

    viewer.removeAllPointClouds();
    viewer.removeAllShapes();

    viewer.addPointCloud(cloud_in_ptr);

    pcl_visualizer_show(viewer, 400);
  }
  return 0;
}
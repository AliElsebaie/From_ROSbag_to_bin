#include <iostream>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main (int argc, char** argv){
    
    //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);

    // pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> intensity_distribution(cloud,"intensity");

    // viewer->addPointCloud<pcl::PointXYZI> (cloud, intensity_distribution, "source");



  if (pcl::io::loadPCDFile<pcl::PointXYZI> ("/home/mohamedaboushenif/Desktop/rosbags/rosbag1/1585830610.770500032.pcd", *cloud) == -1){
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }





  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  FILE * stream; 
  stream = fopen ("pcdfile.bin","wb");
         
  for (std::size_t i = 0; i < cloud->points.size (); ++i){
    std::cout << "    " << cloud->points[i].x
              << " "    << cloud->points[i].y
              << " "    << cloud->points[i].z 
              << " "    << cloud->points[i].intensity << std::endl;

    float data[4]={cloud->points[i].x,cloud->points[i].y,cloud->points[i].z,cloud->points[i].intensity};
    fwrite(data,sizeof(float),sizeof(data),stream);

  }
  fclose(stream);



  return (0);
}
# From_ROSbag_to_bin
Code that converts point cloud ROSbag into binary files.

## Step 1:
Extract the PCD files from your rosbag folder.
```bash
rosrun pcl_ros bag_to_pcd <input_file.bag> <topic> <output_directory>
```
## Step 2:
Clone this repo
```bash
git clone https://github.com/AliElsebaie/From_ROSbag_to_bin.git
```
## Step 3:
Put your PCD files into "pcd_files" folder.

## Step 4:
Run the following:
```bash
mkdir build
cd build
cmake ..
make
./pcd_read
```
## Step 5:
You will find the converted binary files in the "bin_files" folder


#pragma once

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

class column_window{
public:
	column_window(unsigned int column_num, double max_value, int width,int heigh, std::string wondow_name);
	~column_window();
	bool update_data(std::vector<double> datalist);

private:
	void show_framework();


	unsigned int column_num;
	double max_value;
	int width;
	int height;
	std::string window_name;

	
	int column_interval;
	int column_width;
	int column_height;
	int bottom_height;
	std::vector<std::pair<int, int>> column_horizontal_coordinates;

	cv::Mat mat;
};


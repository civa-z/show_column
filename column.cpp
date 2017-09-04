#include "column.h"


column_window::column_window(unsigned int column_num, double max_value, int width, int height, std::string window_name):
		column_num(column_num), max_value(max_value), width(width), height(height), window_name(window_name){
	int column_base = width / (column_num * 3 + 1);
	this->column_interval = column_base;
	this->column_width = column_base * 2;
	this->bottom_height = 40;
	this->column_height = this->height - this->bottom_height;

	for (unsigned int i = 0; i < this->column_num; ++i){
		std::pair<int, int> coordinate;
		coordinate.first = column_base * (3 * i + 1) ;
		coordinate.second = coordinate.first + column_base * 2;
		this->column_horizontal_coordinates.push_back(coordinate);
	}

	this->mat = cv::Mat(height, width, CV_8UC3, cv::Scalar(255, 255, 255));
	show_framework();
}

column_window::~column_window(){
	this->mat.release();
}


bool column_window::update_data(std::vector<double> datalist){
	if (datalist.size() != this->column_num)
		return false;
	int vertical_coordinate_bottom = this->column_height;

	for (unsigned int i = 0; i < this->column_num; ++i){
		cv::rectangle(this->mat, cv::Point(this->column_horizontal_coordinates[i].first, vertical_coordinate_bottom),
			cv::Point(this->column_horizontal_coordinates[i].second, int(vertical_coordinate_bottom * (1 - datalist[i]))), cv::Scalar(50, 200, 50), -1);
		cv::rectangle(this->mat, cv::Point(this->column_horizontal_coordinates[i].first, 0),
			cv::Point(this->column_horizontal_coordinates[i].second, int(vertical_coordinate_bottom * (1 - datalist[i]))), cv::Scalar(200, 200, 200), -1);
	}
	cv::imshow(this->window_name, this->mat);
	return true;
}

void column_window::show_framework(){
	for (unsigned int i = 0; i < this->column_num; ++i){
		int text_column_start = this->column_horizontal_coordinates[i].first;
		int text_row_start = this->height - 10;
		cv::putText(this->mat, std::to_string(i + 1), cv::Point(text_column_start, text_row_start), cv::FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0, 0, 0), 1, CV_AA);
	}
    cv::imshow(this->window_name, this->mat);
}

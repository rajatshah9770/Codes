#pragma once
#include <iostream>

class SingletonGameSetting
{
	static SingletonGameSetting* gameSetting; //1. Compulsory required static member variable
	int brightness;
	int width;
	int height;
	SingletonGameSetting() : brightness(75), width(512), height(1080) {} //2. Private constructor mandatory
public:
	static SingletonGameSetting* getInstance()
	{
		//locking mechanism can be added here for thread safety
		if (gameSetting == nullptr){
			//lock mutex
			//double check
			if (gameSetting == nullptr)
			{
				gameSetting = new SingletonGameSetting();
			}
			//unlock mutex
		}
		return gameSetting;
	}
	int getBrightness() const { return brightness; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	void setBrightness(int b) { brightness = b; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; } 

	void displaySettings() const
	{
		std::cout << "Brightness: " << brightness << ", Width: " << width << ", Height: " << height << std::endl;
	}
};

//Issue with singleton pattern is that while using in multi-threaded environment, multiple instance can be created.
//To avoid that locking mechanism can be added in getInstance method.
//Also memory allocated for singleton instance is never deallocated. To avoid that smart pointer can be used.
//Or a static method can be created to delete the instance when not needed.
//After adding locking mechanism and memory deallocation, singleton pattern can be used in multi-threaded environment safely. But it reduces the performance.

//Approach 1: Using mutex lock in getInstance method. This is not efficient as lock is required only when instance is created first time.
//Approach 2: eager initialization. Instance is created at the time of static member variable declaration. This is thread-safe but instance is created even if it is not used.
//Approach 3: Double-checked locking. Lock is required only when instance is created first time. This is efficient and thread-safe.
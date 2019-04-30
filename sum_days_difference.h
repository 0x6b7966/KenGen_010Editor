#ifndef SUM_DAYS_DIFFERENCE_H
#define SUM_DAYS_DIFFERENCE_H
#pragma once
#include <Windows.h>

// 判断是否是闰年
BOOL IsLeapYear( int year );

// 获取某一年所有天数
int GetYearAllDays( int year );

// 计算输入日期距 年初/年底的天数
int GetYearSumDays( int year, int mounth, int day, bool isBegin );

// 当年份相同，根据月份、天计算相差天数
int GetMounthSumDays( int mounthBegin, int dayBegin,
					  int mounthEnd, int dayEnd,
					  bool flag );

// 当同年、同月，根据天数计算差值
int GetSumDays( int dayBegin, int dayEnd );

// 参数互换
void ReData( int &arg1, int &arg2 );

// 如果输入日期1 > 日期2，则发生互换
BOOL ReDate( int &yearBegin, int &mounthBegin, int &dayBegin,
			 int &yearEnd, int &mounthEnd, int &dayEnd );

// 根据年、月、日计算相距天数（可计算负值）
int GetSumDaysDifference( int yearBegin, int mounthBegin, int dayBegin,
						  int yearEnd, int mounthEnd, int dayEnd );
#endif // SUM_DAYS_DIFFERENCE_H

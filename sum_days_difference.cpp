#include "sum_days_difference.h"


int leap_year_mounth_array[ 12 ] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int common_year_mounth_array[ 12 ] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
/**
 * \brief 判断是否是闰年
 * \param year
 * \return TRUE/FALSE
 */
BOOL IsLeapYear( int year )
{
	if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
		return TRUE;
	else
		return FALSE;
}

/**
 * \brief 获取某一年所有天数
 * \param year
 * \return 天数
 */
int GetYearAllDays( int year )
{
	if ( IsLeapYear( year ) )
		return 366;
	else
		return 365;
}



/**
 * \brief 计算输入日期距 年初/年底的天数
 * \param year
 * \param mounth
 * \param day
 * \param isBegin true：日期1 false：日期2
 * \return sumDays
 */
int GetYearSumDays( int year, int mounth, int day, bool isBegin )
{
	int sum = 0;
	BOOL flag = IsLeapYear( year );
	if ( isBegin ) // 日期1
	{
		// 计算 月份+1 到 12月 总天数
		for ( int index = mounth; index < 12; index++ )
		{
			if ( flag )
				sum += leap_year_mounth_array[ index ];
			else
				sum += common_year_mounth_array[ index ];
		}
		// 根据月份、日 计算到月底的天数并求和  eg：1.1  sum = 30
		if ( flag )
			sum += ( leap_year_mounth_array[ mounth - 1 ] - day );
		else
			sum += ( common_year_mounth_array[ mounth - 1 ] - day );
	}
	else           // 日期2
	{
		// 计算 1月 到 12 - 1月 总天数
		for ( int index = 0; index < mounth - 1; index++ )
		{
			if ( flag )
				sum += leap_year_mounth_array[ index ];
			else
				sum += common_year_mounth_array[ index ];
		}
		// 加上剩余天数
		if ( flag )
			sum += day;
		else
			sum += day;
	}
	return sum;
}


/**
 * \brief 当年份相同，根据月份、天计算相差天数
 * \param mounthBegin
 * \param dayBegin
 * \param mounthEnd
 * \param dayEnd
 * \param flag
 * \return sumDays
 */
int GetMounthSumDays( int mounthBegin, int dayBegin,
					  int mounthEnd, int dayEnd,
					  bool flag )
{
	int sum = 0;
	// 计算 mounthBegin 到 mounthEnd - 1 月份的天数
	for ( int index = mounthBegin; index < mounthEnd - 1; index++ )
	{
		if ( flag )
			sum += leap_year_mounth_array[ index ];
		else
			sum += common_year_mounth_array[ index ];
	}
	// 计算剩余天数
	if ( flag )
		sum = sum + ( leap_year_mounth_array[ mounthBegin - 1 ] - dayBegin ) + dayEnd;
	else
		sum = sum + ( common_year_mounth_array[ mounthBegin - 1 ] - dayBegin ) + dayEnd;
	return sum;
}

/**
 * \brief 当同年、同月，根据天数计算差值
 * \param dayBegin
 * \param dayEnd
 * \return sumDays
 */
int GetSumDays( int dayBegin, int dayEnd )
{
	return dayEnd - dayBegin;
}

/**
 * \brief 参数互换
 * \param arg1
 * \param arg2
 */
void ReData( int &arg1, int &arg2 )
{
	int temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

/**
 * \brief 如果输入日期1 > 日期2，则发生互换
 * \param yearBegin
 * \param mounthBegin
 * \param dayBegin
 * \param yearEnd
 * \param mounthEnd
 * \param dayEnd
 */
BOOL ReDate( int &yearBegin, int &mounthBegin, int &dayBegin,
			 int &yearEnd, int &mounthEnd, int &dayEnd )
{
	if ( yearBegin > yearEnd )
	{
		ReData( yearBegin, yearEnd );
		ReData( mounthBegin, mounthEnd );
		ReData( dayBegin, dayEnd );
		return TRUE;
	}
	else if ( yearBegin == yearEnd && mounthBegin > mounthEnd )
	{
		ReData( mounthBegin, mounthEnd );
		ReData( dayBegin, dayEnd );
		return TRUE;
	}
	else if ( yearBegin == yearEnd && mounthBegin == mounthEnd && dayBegin > dayEnd )
	{
		ReData( dayBegin, dayEnd );
		return TRUE;
	}
	return FALSE;
}

/**
 * \brief 根据年、月、日计算相距天数（可计算负值）
 * \param yearBegin
 * \param mounthBegin
 * \param dayBegin
 * \param yearEnd
 * \param mounthEnd
 * \param dayEnd
 * \return sumDays
 */
int GetSumDaysDifference( int yearBegin, int mounthBegin, int dayBegin,
						  int yearEnd, int mounthEnd, int dayEnd )
{
	int count = 0;
	BOOL reFlag = ReDate( yearBegin, mounthBegin, dayBegin,
						  yearEnd, mounthEnd, dayEnd );
	if ( yearEnd - yearBegin > 1 ) // 当年数相差大于1时 eg：2000~2002
	{
		for ( int year = yearBegin + 1; year < yearEnd; year++ )
		{
			count += GetYearAllDays( year );
		}
		count += GetYearSumDays( yearBegin, mounthBegin, dayBegin, true );
		count += GetYearSumDays( yearEnd, mounthEnd, dayEnd, false );
	}
	else if ( yearEnd - yearBegin == 1 ) // 当年数相差等于1 eg：2000~2001
	{
		count += GetYearSumDays( yearBegin, mounthBegin, dayBegin, true );
		count += GetYearSumDays( yearEnd, mounthEnd, dayEnd, false );
	}
	else if ( yearBegin == yearEnd && mounthBegin != mounthEnd ) // 年数相同，月份不同
	{

		count = GetMounthSumDays( mounthBegin, dayBegin, mounthEnd, dayEnd, IsLeapYear( yearBegin ) );
	}
	else if ( yearBegin == yearEnd && mounthBegin == mounthEnd ) // 天数不同
	{
		count = GetSumDays( dayBegin, dayEnd );
	}
	if ( reFlag )
		return ~count + 1;
	else
		return count;
}

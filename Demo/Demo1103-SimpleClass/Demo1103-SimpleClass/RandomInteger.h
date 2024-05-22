#pragma once

class RandomInteger {
public:
	RandomInteger();
public:
	/// <summary>
	/// Trả ra số nguyên ngẫu nhiên
	/// </summary>
	/// <returns>Số nguyên trong đoạn [0, 65535]</returns>
	int next();

	/// <summary>
	/// Trả ra số nguyên ngẫu nhiên
	/// </summary>
	/// <param name="max">Giá trị tối đa</param>
	/// <returns>Số nguyên trong đoạn [0, max)</returns>
	int next(int max);

	/// <summary>
	/// Sinh số ngẫu nhiên
	/// </summary>
	/// <param name="left">Biên trái</param>
	/// <param name="right">Biên phải</param>
	/// <returns>Số nguyên trong đoạn [left, right]</returns>
	int next(int left, int right);
};
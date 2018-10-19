#pragma once

template <typename T>
T min(T num1, T num2) {
	if (num1 < num2) {
		return num1;
	}
	// else
	return num2;
}

template <typename T>
T max(T num1, T num2) {
	if (num1 > num2) {
		return num1;
	}
	// else
	return num2;
}
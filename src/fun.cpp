// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>

unsigned int faStr1(const char* str) {
	std::stringstream ss(str);
	std::string word;
	unsigned int count = 0;

	while (ss >> word) {
		bool has_digits = false;
		for (char c : word) {
			if (std::isdigit(c)) {
				has_digits = true;
				break;
			}
		}
		if (!has_digits) {
			++count;
		}
	}

	return count;
}

unsigned int faStr2(const char* str) {
	unsigned int count = 0;
	const int len = std::strlen(str);
	bool is_word = false;

	for (int i = 0; i < len; i++) {
		if (std::isupper(str[i])) {
			if (!is_word) {
				bool has_lower = true;
				int j = i + 1;
				while (j < len && !std::isspace(str[j])) {
					if (!std::islower(str[j])) {
						has_lower = false;
						break;
					}
					j++;
				}
				if (has_lower) {
					count++;
					is_word = true;
				}
			}
		} else {
			is_word = false;
		}
	}

	return count;
}

unsigned int faStr3(const char* str) {
	unsigned int word_count = 0;
	unsigned int total_length = 0;
	unsigned int current_length = 0;

	for (int i = 0; i < strlen(str); ++i) {
		if (!isspace(str[i])) {
			current_length++;
		} else {
			if (current_length > 0) {
				word_count++;
				total_length += current_length;
				current_length = 0;
			}
		}
	}

	if (current_length > 0) {
		word_count++;
		total_length += current_length;
	}

	return word_count == 0 ? 0 : (total_length + word_count / 2) / word_count;
}

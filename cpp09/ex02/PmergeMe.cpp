#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

VectorFJ::VectorFJ() {}
VectorFJ::~VectorFJ() {}
VectorFJ::VectorFJ(const VectorFJ& rhs) {(void)rhs;}
VectorFJ& VectorFJ::operator=(const VectorFJ& rhs) {(void)rhs; return *this;}

void	VectorFJ::makeVector(int ac, char* av[]) {
	start = clock();
	for (int i = 1; i < ac; i++) {
		long tmp;
		tmp = std::strtol(av[i], 0, 10);
		if (tmp <= 0 || tmp > 2147483647) throw 1;
		v.push_back(tmp);
	}
}

void	VectorFJ::execute() {
	std::vector<std::pair<long, long> > pv;
	for (size_t i = 0; i < v.size(); i++) pv.push_back(std::make_pair(v[i], i));
	pv = mergeInsertion(pv, 1);
	end = clock();
	for	(size_t i = 0; i < v.size(); i++) v[i] = pv[i].first;
}

std::vector<std::pair<long, long> > VectorFJ::mergeInsertion(std::vector<std::pair<long, long> > v, int dep) {
	std::vector<std::pair<long, long> > main;
	std::vector<std::pair<long, long> > sub;
	if (v.size() == 1) return v;
	for (size_t i = 0; i < v.size() / 2; i++) {
		main.push_back(std::max(v[i * 2], v[i * 2 + 1]));
		sub.push_back(std::min(v[i * 2], v[i * 2 + 1]));
	}
	if (v.size() % 2 == 1) sub.push_back(v[v.size() - 1]);
	std::vector<std::pair<long, long> > tmp(sub);
	main = mergeInsertion(main, dep + 1);
	for (size_t i = 0; i < main.size(); i++)
		sub[i] = tmp[main[i].second / std::pow(2, dep)];
	tmp = main;
	tmp.insert(tmp.begin(), sub[0]);
	size_t t, t1 = 1, t2 = 3;
	while (t1 < sub.size()) {
		size_t m = std::min(t2, sub.size());
		size_t u = t1 + m;
		for (size_t i = m - 1; i >= t1; i--)
			tmp.insert(std::lower_bound(tmp.begin(), tmp.begin() + u - 1, sub[i]), sub[i]);
		t = t2;
		t2 = t2 + t1 * 2;
		t1 = t;
	}
	return tmp;
}

void	VectorFJ::print() {
	flag = 1;
	std::cout << "Vector After:   ";
	for (size_t i = 0; i < v.size(); i++) {
		if (i > 0 && v[i - 1] > v[i]) flag = 0;
		std::cout << v[i] << ' ';
	}
	std::cout << '\n';
}

void	VectorFJ::result() {
	std::cout << "Vector Sorted:  " << std::boolalpha << flag << '\n';
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << (end - start) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
}

DequeFJ::DequeFJ() {}
DequeFJ::~DequeFJ() {}
DequeFJ::DequeFJ(const DequeFJ& rhs) {(void)rhs;}
DequeFJ& DequeFJ::operator=(const DequeFJ& rhs) {(void)rhs; return *this;}

void	DequeFJ::makeDeque(int ac, char* av[]) {
	start = clock();
	for (int i = 1; i < ac; i++) {
		long tmp;
		tmp = std::strtol(av[i], 0, 10);
		if (tmp <= 0 || tmp > 2147483647) throw 1;
		dq.push_back(tmp);
	}
}

void	DequeFJ::execute() {
	std::deque<std::pair<long, long> > pv;
	for (size_t i = 0; i < dq.size(); i++) pv.push_back(std::make_pair(dq[i], i));
	pv = mergeInsertion(pv, 1);
	for	(size_t i = 0; i < dq.size(); i++) dq[i] = pv[i].first;
	end = clock();
}

std::deque<std::pair<long, long> > DequeFJ::mergeInsertion(std::deque<std::pair<long, long> > dq, int dep) {
	std::deque<std::pair<long, long> > main;
	std::deque<std::pair<long, long> > sub;
	if (dq.size() == 1) return dq;
	for (size_t i = 0; i < dq.size() / 2; i++) {
		main.push_back(std::max(dq[i * 2], dq[i * 2 + 1]));
		sub.push_back(std::min(dq[i * 2], dq[i * 2 + 1]));
	}
	if (dq.size() % 2 == 1) sub.push_back(dq[dq.size() - 1]);
	std::deque<std::pair<long, long> > tmp(sub);
	main = mergeInsertion(main, dep + 1);
	for (size_t i = 0; i < main.size(); i++)
		sub[i] = tmp[main[i].second / std::pow(2, dep)];
	tmp = main;
	tmp.insert(tmp.begin(), sub[0]);
	size_t t, t1 = 1, t2 = 3;
	while (t1 < sub.size()) {
		size_t m = std::min(t2, sub.size());
		size_t u = t1 + m;
		for (size_t i = m - 1; i >= t1; i--)
			tmp.insert(std::lower_bound(tmp.begin(), tmp.begin() + u - 1, sub[i]), sub[i]);
		t = t2;
		t2 = t2 + t1 * 2;
		t1 = t;
	}
	return tmp;
}

void	DequeFJ::print() {
	flag = 1;
	std::cout << "Deque  After:   ";
	for (size_t i = 0; i < dq.size(); i++) {
		if (i > 0 && dq[i - 1] > dq[i]) flag = 0;
		std::cout << dq[i] << ' ';
	}
	std::cout << '\n';
}

void	DequeFJ::result() {
	std::cout << "Deque  Sorted:  " << std::boolalpha << flag << '\n';
	std::cout << "Time to process a range of " << dq.size() << " elements with std::deque  : " << (end - start) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
}
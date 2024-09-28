#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<regex>
using namespace std;
int Ackerman(int n, int m) {
	stack<int>st;
	st.push(m);
	while (!st.empty()) {
		m = st.top();
		st.pop();
		if (m == 0 && n == 1) {
			n = 2;
		}
		else if (n == 0) {
			n = 1;
		}
		else if (m == 0&&n>=2) {
			n += 2;
		}
		else {
			st.push(m - 1);
			st.push(m);
			n -= 1;
		}
	}
	return n;
}
//int Ackerman(int n, int m) {
//	stack<int>st;
//	st.push(m);
//	while (!st.empty()) {
//		m = st.top();
//		st.pop();
//		if (m == 0) {
//			n = n + 1;
//		}
//		else if (n == 0) {
//			st.push(m - 1);
//			n =1;
//		}
//		else {
//			st.push(m - 1);
//			st.push(m);
//			n -= 1;
//		}
//	}
//	return n;
//}
//void parse(string& expression, double& a, double& b, double& c) {
//    regex regexA("([+-]?\\d*\\.?\\d*)x\\^2");
//    regex regexB("([+-]?\\d*\\.?\\d*)x(?!\\^)");
//    regex regexC("([+-]?\\d+\\.?\\d*)(?!x)");
//    smatch match;
//    if (regex_search(expression, match, regexA)) {
//        a = match.str(1).empty() || match.str(1) == "+" || match.str(1) == "-" ? (match.str(1) == "-" ? -1 : 1) : std::stod(match.str(1));
//    }
//    else {
//        a = 0;
//    }
//    if (regex_search(expression, match, regexB)) {
//        b = match.str(1).empty() || match.str(1) == "+" || match.str(1) == "-" ? (match.str(1) == "-" ? -1 : 1) : std::stod(match.str(1));
//    }
//    else {
//        b = 0;
//    }
//    if (regex_search(expression, match, regexC)) {
//        c = stod(match.str(1));
//    }
//    else {
//        c = 0;
//    }
//}
//double evaluate(double a, double b, double c, double x) {
//    return a * pow(x, 2) + b * x + c;
//}
//void parse(string& expression, double& a, double& b, double& c) {
//    regex regexA("([+-]?\\d*\\.?\\d*)x\\^2");
//    regex regexB("([+-]?\\d*\\.?\\d*)x(?!\\^)");
//     regex regexC("([+-]?\\d+\\.?\\d*)(?!x)");   
//     smatch match;
//    if (std::regex_search(expression, match, regexA)) {
//        a = match.str(1).empty() || match.str(1) == "+" || match.str(1) == "-" ? (match.str(1) == "-" ? -1 : 1) : std::stod(match.str(1));
//    }
//    else {
//        a = 0; 
//    }
//    if (std::regex_search(expression, match, regexB)) {
//        b = match.str(1).empty() || match.str(1) == "+" || match.str(1) == "-" ? (match.str(1) == "-" ? -1 : 1) : std::stod(match.str(1));
//    }
//    else {
//        b = 0;
//    }
//    if (std::regex_search(expression, match, regexC)) {
//        c = std::stod(match.str(1));
//    }
//    else {
//        c = 0;
//    }
//}
double evaluate(double a, double b, double c, double x) {
    return a * pow(x, 2) + b * x + c;
}
double total(int n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	return total(n - 1) + total(n - 2);
}

double sum(double x, int n) {
	if (n == 1)return 1;
	if (n % 2 == 1) {
	int res=1;
	for (int i = 1; i <= 2*n-1; i++) {
		res *= i;
	}
		return double(pow(x, double(2 * n - 1)))/res + sum(x, --n);
	}
	else {
		int res = 1;
		for (int i = 1; i <= 2*n-1; i++) {
			res *= i;
		}
		return double( - pow(x, double(2 * n - 1)) / res) + sum(x, --n);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << Ackerman(n, m);
	return 0;
}
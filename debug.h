#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

//debugging code segment
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__); cerr << "]" << endl;
#else
#define dbg(...)
#endif

void _print() { cerr << ""; }

template<typename T> 
void _print(T t) { cerr << t; }

template<typename T, typename... V> 
void _print(T t, V... v) { 
    cerr << t; 
    if(sizeof...(v)) cerr << ", "; 
    _print(v...); 
}

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> 
void _print(pair <T, V> p);

template <class T> 
void _print(vector <T> v);

template <class T> 
void _print(set <T> v);

template <class T, class V> 
void _print(map <T, V> v);

template <class T> 
void _print(multiset <T> v);

template <class T, class V> 
void _print(pair <T, V> p) {
    cerr << "{"; 
    _print(p.first); 
    cerr << ","; 
    _print(p.second); 
    cerr << "}";
}

template <class T> 
void _print(vector <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

template <class T> 
void _print(set <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

template <class T> 
void _print(multiset <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

template <class T, class V> 
void _print(map <T, V> v) {
    cerr << "[ "; 
    for (auto i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

#endif // DEBUG_H

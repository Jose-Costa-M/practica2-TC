/*
 *  File : head.h
 *  Autor: Jose Clavero y Charlie parra
 *  Fecha: 9 de noviembre del 2022 
 *  Problema: PRACTICA 2 TEORIA COMPUTACIONAL
*/

#include <bits/stdc++.h>

 
using namespace std;
 
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define lambda "\0"
#define vt vector
#define str string 
#define fi first
#define se second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define szi(x) (int)(x).size()
#define szl(x) (lli)(x).size()
 
#define all(v) (v).begin(), (v).end()
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define gauss(n) (n*(n+1)/2)
 
#define each(x,a) for(auto &x: a)
 
#define forM(i,a,b,t,s) for(t i = t(a); i < t(b); i+=s)
#define forMe(i,a,b,t,s) for(t i = t(a); i <= t(b); i+=s)
 
#define forr(i,a) for(int i = (a)-1; i >= 0; i--)
#define forra(i,a,b) for(int i = (b)-1; i >= a; i--)
#define fori(i,b) forM(i,0,b,int,1)
#define forie(i,b) forMe(i,0,b,int,1)
#define forl(i,b) forM(i,0,b,lli,1)
#define forle(i,b) forMe(i,0,b,lli,1)
 
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef pair<ld, ld> pdd;
typedef set<string> alfabeto;
typedef set<string> prefijo;
typedef set<string> sufijo;
typedef set<string> lenguaje;
typedef vt<int> vi;
typedef vt<vi> vvi;
typedef vt<pii> vpi;
typedef vt<ll> vll;
typedef vt<lli> vli;
typedef complex<ld> cd;
typedef unordered_multiset<string> cadena_validar;
 
const double PI = acos(-1.0);

void menu(); 




//AUTOMATA 1: 
void problema1();
bool AFD1(string cadena);
bool ESTADO_Q0(string cadena);
bool ESTADO_Q1(string cadena);
bool ESTADO_Q2(string cadena);
bool ESTADO_Q3(string cadena);
bool ESTADO_Q4(string cadena);
bool ESTADO_Q5(string cadena);
bool ESTADO_Q6(string cadena);
bool ESTADO_Q7(string cadena);

//AUTOMATA 2:
void problema2();
bool AFD2(string cadena);
bool ESTADO_Q0_2(string cadena);
bool ESTADO_Q1_2(string cadena);
bool ESTADO_Q2_2(string cadena);
bool ESTADO_Q3_2(string cadena);
bool ESTADO_Q4_2(string cadena);





//AUTOMATA 3:
void problema3();
bool AFD3(string cadena);
bool ESTADO_Q0_3(string cadena);
bool ESTADO_Q1_3(string cadena);
bool ESTADO_Q2_3(string cadena);
bool ESTADO_Q3_3(string cadena);
bool ESTADO_Q4_3(string cadena);
bool ESTADO_Q5_3(string cadena);

//AUTOMATA 4:
void problema4();
bool AFD4(string cadena);
bool ESTADO_Q0_4(string cadena);
bool ESTADO_Q1_4(string cadena);
bool ESTADO_Q2_4(string cadena);
bool ESTADO_Q3_4(string cadena);
bool ESTADO_Q4_4(string cadena);
bool ESTADO_Q5_4(string cadena);
bool ESTADO_Q6_4(string cadena);
bool ESTADO_Q7_4(string cadena);
bool ESTADO_Q8_4(string cadena);
bool ESTADO_Q9_4(string cadena);
bool ESTADO_Q10_4(string cadena);
bool ESTADO_Q11_4(string cadena);
bool ESTADO_Q12_4(string cadena);
bool ESTADO_Q13_4(string cadena);
bool ESTADO_Q14_4(string cadena);
bool ESTADO_Q15_4(string cadena);
bool ESTADO_Q16_4(string cadena);
bool ESTADO_Q17_4(string cadena);
bool ESTADO_Q18_4(string cadena);

void limpiar();





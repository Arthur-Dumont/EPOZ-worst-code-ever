#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
class A {
public:
    string h, n, t; double b; vector<string> th;
    A(string hh, string nn, double bb, string tt) : h(hh), n(nn), b(bb), t(tt) {}
    void d(double amt) {b += amt; th.push_back("Deposited: " + to_string(amt));}
    void w(double amt) {if(b >= amt) {b -= amt; th.push_back("Withdrew: " + to_string(amt));} else th.push_back("Failed Withdrawal: Insufficient funds");}
    void p() {cout << "Holder: " << h << "\nNo: " << n << "\nType: " << t << "\nBalance: " << b << "\nHistory:\n"; for(auto& tx : th) cout << tx << "\n";}};
class G {
public:
    vector<A> a;
    bool e(string nn) {for(auto& acc : a) if(acc.n == nn) return true; return false;}
    A* g(string nn) {for(auto& acc : a) if(acc.n == nn) return &acc; return nullptr;}
    void c() {string hh, nn, tt; double dd; cout << "Enter name: "; cin >> hh; cout << "Enter account number: "; cin >> nn; if(e(nn)) {cout << "Account exists.\n"; return;} cout << "Enter type (Savings/Checking): "; cin >> tt; cout << "Enter deposit: "; cin >> dd; if(dd < 0) {cout << "Invalid deposit.\n"; return;} a.push_back(A(hh, nn, dd, tt)); cout << "Account created.\n";}
    void dep() {string nn; double amt; cout << "Enter number: "; cin >> nn; A* acc = g(nn); if(!acc) {cout << "Account not found.\n"; return;} cout << "Deposit: "; cin >> amt; if(amt <= 0) {cout << "Invalid amount.\n"; return;} acc->d(amt); cout << "Deposit successful.\n";}
    void wd() {string nn; double amt; cout << "Enter number: "; cin >> nn; A* acc = g(nn); if(!acc) {cout << "Account not found.\n"; return;} cout << "Withdraw: "; cin >> amt; if(amt <= 0) {cout << "Invalid amount.\n"; return;} acc->w(amt); cout << "Withdrawal successful.\n";}
    void v() {string nn; cout << "Enter number: "; cin >> nn; A* acc = g(nn); if(!acc) {cout << "Account not found.\n"; return;} acc->p();}
    void m() {int ch; while(true) {cout << "\n1. Create\n2. Deposit\n3. Withdraw\n4. View\n5. Exit\nChoice: "; cin >> ch; switch(ch) {case 1: c(); break; case 2: dep(); break; case 3: wd(); break; case 4: v(); break; case 5: exit(0); break; default: cout << "Invalid choice.\n"; break;}}}};
class U {
public:
    string u, p;
    bool a(string uu, string pp) {return uu == u && pp == p;}
    void c() {cout << "New username: "; cin >> u; cout << "New password: "; cin >> p; cout << "User created.\n";}
    void l() {string uu, pp; cout << "Username: "; cin >> uu; cout << "Password: "; cin >> pp; if(a(uu, pp)) {cout << "Login successful.\n";} else {cout << "Invalid credentials.\n"; exit(0);}}};
int main() {
    U ua; G b; ua.c(); ua.l(); b.m(); return 0;}
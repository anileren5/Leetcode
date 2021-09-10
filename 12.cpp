class Solution {
public:
    string intToRoman(int num) {
        int i=0,iv=0,v=0,ix=0,x=0,xl=0,l=0,xc=0,c=0,cd=0,d=0,cm=0,m=0;
        string s;
        int j;
        m = num / 1000; num = num % 1000;
        cm = num / 900; num = num % 900;
        d = num / 500; num = num % 500;
        cd = num / 400; num = num % 400;
        c = num / 100; num = num % 100;
        xc = num / 90; num = num % 90;
        l = num / 50; num = num % 50;
        xl = num / 40; num = num % 40;
        x = num / 10; num = num % 10;
        ix = num / 9; num = num % 9;
        v = num / 5; num = num % 5;
        iv = num / 4; num = num % 4;
        i = num / 1; num = num % 1;
        for (j=0;j<m;j++) s += "M";
        for (j=0;j<cm;j++) s += "CM";
        for (j=0;j<d;j++) s += "D";
        for (j=0;j<cd;j++) s += "CD";
        for (j=0;j<c;j++) s += "C";
        for (j=0;j<xc;j++) s += "XC";
        for (j=0;j<l;j++) s += "L";
        for (j=0;j<xl;j++) s += "XL";
        for (j=0;j<x;j++) s += "X";
        for (j=0;j<ix;j++) s += "IX";
        for (j=0;j<v;j++) s += "V";
        for (j=0;j<iv;j++) s += "IV";
        for (j=0;j<i;j++) s += "I";
        return s;
    }
};
## STL Data Structures
###  แบบพื้นๆ

---
- vector
- set
- map
- iterator นิดหน่อย
 
---
### vector (Dynamic Array)

---
ประกาศตัวแปร และเพิ่มค่า
```cpp
vector<int> v;
v.push_back(3); // [3]
v.push_back(2); // [3,2]
v.push_back(5); // [3,2,5]
```
push_back มี Time Complexity เป็น O(1)

---
อ่านค่า
```cpp
cout << v[0] << "\n"; // 3
cout << v[1] << "\n"; // 2
cout << v[2] << "\n"; // 5
```

---
วิธีไล่ค่า vector
```cpp
for (int i = 0; i < v.size(); i++) {
  cout << v[i] << "\n";
}
```

แบบสั้น
```cpp
for (auto x : v) {
  cout << x << "\n";
}
```

---
อ่าน/ลบ ค่าท้ายสุด
```cpp
vector<int> v;
v.push_back(5);
v.push_back(2);
cout << v.back() << "\n"; // 2
v.pop_back();
cout << v.back() << "\n"; // 5
```

---
ประกาศตัวแปรพร้อมกับค่า
```cpp
vector<int> v = {2,4,2,5,1};
```

---
ประกาศตัวแปรพร้อมกับค่าอีกวิธีหนึ่ง
```cpp
// size 10, ค่าทั้งหมดเป็น 0
vector<int> v(10);
// size 10, ค่าทั้งหมดเป็น 5
vector<int> v(10, 5);
```

---
String เป็น Dynamic Array ที่สามารถใช้งานได้คล้ายกับ vector
```cpp
string a = "hatti";
string b = a+a;
cout << b << "\n"; // hattihatti
b[5] = ’v’;
cout << b << "\n"; // hattivatti
string c = b.substr(3,4);
cout << c << "\n"; // tiva
```

---
## set
คือวิธีที่เราจะใช้เก็บค่าไม่ซ้ำกัน และเรียงลำดับจากต่ำไปสูงเสมอ

---
ใน C++ set จะเก็บข้อมูลในรูปแบบของ Balance Binary Tree (Red-Black Tree) ทำให้การทำงานของ set จะอยู่ในความเร็ว O(log n)

unordered_set จะไม่เรียงลำดำค่า และเก็บข้อมูลในรูปแบบ hash table ซื่งทำงานในความเร็ว O(1) โดยเฉลี่ย แต่ O(n) worst-case

---
ตัวอย่างการใช้งาน
```cpp
set<int> s;
s.insert(3);
s.insert(2);
s.insert(5);
cout << s.count(3) << "\n"; // 1
cout << s.count(4) << "\n"; // 0
s.erase(3);
s.insert(4);
cout << s.count(3) << "\n"; // 0
cout << s.count(4) << "\n"; // 1
```

---
set ไม่สามารถใช้ \[\] หาค่าได้เหมือน array ทั่วไป เราสามารถหาขนาด, และค่าของ set ได้ด้วยวิธีนี้
```cpp
set<int> s = {2,5,6,8};
cout << s.size() << "\n"; // 4

for (auto x : s) {
  cout << x << "\n";
}
```

---
เป้าหมายของ set คือการหาค่าที่ไม่ซ้ำกัน ทำให้เราไม่สามารถทราบได้ว่าจำนวนที่เราเพิ่มเข้าไปมีกี่ตัว
```cpp
set<int> s;
s.insert(5);
s.insert(5);
s.insert(5);
cout << s.count(5) << "\n";
```

---
STL ยังมี set อีกแบบนึงที่สามารถรับค่าและอ่านค่าเซตที่มีหลายตัวได้
```cpp
multiset<int> s;
s.insert(5);
s.insert(5);
s.insert(5);
cout << s.count(5) << "\n"; // 3
```

---
ฟังก์ชั่น erase จะลบค่าเซตทุกตัว
```cpp
s.erase(5);
cout << s.count(5) << "\n"; // 0
```

ต้องใช้อีกวิธีถ้าหากอยากลบเพียงค่าเดียว
```cpp
s.erase(s.find(5));
cout << s.count(5) << "\n"; // 2
```

---
## map
คือวิธีหลักๆ ที่เราจะผูกค่า 2 ตัวเข้าด้วยกันด้วยความสัมพันธ์แบบ key-value

ในขณะที่ key ของ array คือเลข 0, 1, ... key ของ map สามารถเป็นประเภทอะไรก็ได้ แล้วไม่จำเป็นต้องเรียงกันด้วย

---
ใน C++ map จะเก็บข้อมูลคล้ายกับ set (balanced binary tree) ทำให้การเข้าถึงค่าเป็น O(log n) และ unordered_map จะใช้ hash ซึ่งเป็น O(1) โดยเฉลี่ย, O(n) worst-case

---
ตัวอย่างการใช้งาน
```cpp
map<string,int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;
cout << m["banana"] << "\n"; // 3
cout << m["banana"].count;   // 1
```

---
ถ้าเรียกหาค่าของ key ที่ไม่ได้ตั้งไว้ จะคืนค่าเป็น 0 (default value)
```cpp
map<string,int> m;
cout << m["aybabtu"] << "\n"; // 0
```

---
กรณีที่จะไล่ดูค่าทั้งหมด
```cpp
for (auto x : m) {
  cout << x.first << " " << x.second << "\n";
}
```

---
### Iterators
หลายฟังก์ชั่นใน C++ ใช้ Iterator ซื่งเป็นค่าที่ชี้ให้เห็นค่าแต่ละค่าใน Data Structure

---
ที่ได้ใช้บ่อยๆ คือ begin และ end โดยที่การทำงานจะเป็นแบบนี้

![iterator](/Lectures/Assets/iterator.png)

---
ฟังก์ชั่นที่จะได้ใช้บ่อย
```cpp
sort(v.begin(), v.end());    //O(n log n)
reverse(v.begin(), v.end()); //O(n)
```

---
### ตะลุยโจทย์
## Sorting and Searching
---
### [Distinct Numbers](https://cses.fi/problemset/task/1621)

---
### [Apartments](https://cses.fi/problemset/task/1084)

---
### [Ferris Wheel](https://cses.fi/problemset/task/1090)

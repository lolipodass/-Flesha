'use strict';

function Group(number, name, amount) {
    this.number = number;
    this.name = name;
    this.amount = amount;
    this.increase = function(amount) {
        this.amount += amount;
    }
    this.decrease = function(amount) {
        this.amount -= amount;
    }
}

function Student(name, surname, physics, math, info) {
    this.name = name;
    this.surname = surname;
    this.physics = physics;
    this.math = math;
    this.info = info;
    this.FIO = function() {
        console.log(name, surname);
    }
    this.average = function() {
        console.log((this.physics + this.math + this.info) / 3);
    }
}

function return5() {
    return 5;
}

console.group(1);


let gr1 = new Group(1, "ИСИТ", 30);
let gr2 = new Group(2, "ПОИТ", 27);
let gr3 = new Group(3, "ПОИБМС", 29);
let gr4 = new Group(4, "ДЭВИ", 31);

console.log(gr1.name, gr2.name, gr3.name, gr4.name);
console.log(gr1.amount, gr2.amount, gr3.amount, gr4.amount);

gr1.decrease(2);
gr2.decrease(2);
gr3.decrease(2);
gr4.decrease(2);
console.log(gr1.amount, gr2.amount, gr3.amount, gr4.amount);
gr1.increase(2);
gr2.increase(2);
gr3.increase(2);
gr4.increase(2);
console.log(gr1.amount, gr2.amount, gr3.amount, gr4.amount);

console.groupEnd();

//!second

console.group(2);

let stud1 = new Student("da", "jo", 20, 30, 40);
let stud2 = new Student("net", "ok", 10, 30, 44);
let stud3 = new Student("ro", "pa", 23, 40, 43);
Student.prototype.da = function() {
    console.log("duck");
}

console.log("check func")

stud1.FIO();
stud1.average();


console.groupEnd();

//!third

console.group(3);

let acc = [4];
acc[0] = 6 * Math.PI * Math.PI + 3 * Math.exp(8);
acc[1] = 2 * Math.cos(4) + Math.cos(12) + 8 * Math.exp(9);
acc[2] = 3 * Math.sin(9) + Math.log(5) + Math.sqrt(3);
acc[3] = 2 * Math.tan(5) + 6 * Math.PI + Math.sqrt(12);


console.log(acc);
delete acc[2];
console.log(acc);
if (2 in acc)
    console.log("da");
else console.log("no");
if (da in stud1)
    console.log("da");
else console.log("no");


console.log('%c instanceof', 'background: #2222; color: #bada554');
console.log(acc instanceof Array);
console.log(stud1 instanceof Array);
console.log(stud1 instanceof Student);

console.warn("typeof");
console.log(typeof return5);
console.log(typeof return5());


console.groupEnd();
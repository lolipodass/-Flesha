"use strict";


let acc = [4];
acc[0] = 6 * Math.PI * Math.PI + 3 * Math.exp(8);
acc[1] = 2 * Math.cos(4) + Math.cos(12) + 8 * Math.exp(9);
acc[2] = 3 * Math.sin(9) + Math.log(5) + Math.sqrt(3);
acc[3] = 2 * Math.tan(5) + 6 * Math.PI + Math.sqrt(12);


let min = acc[0],
    max = acc[0];


for (let da of acc) {
    if (da < min) {
        min = da;
    }
    if (da > max) {
        max = da;
    }
}

console.log(min, max);


//!second
let omega = {
    da: "dop",
    far: function() {
        console.log("joper");
    },
};


let acc2 = ["pow", "pop", "push", "shift", "round", "floor", "sline", "sort"];
let metMath = [];
let metArr = [];

for (let da of acc2) {
    if (undefined != Math[da]) {
        metMath.push(da);
    }
    if (undefined != acc2[da]) {
        metArr.push(da);
    }
}
metMath.push("PI");
metArr.unshift("unshift");
console.log(metMath, metArr);

//!third

let stroka = new String("Ковалев Андрей Леоидович");
console.log("Данные по умолчанию = ", stroka);
console.log("Длина строки = ", +stroka.length);
stroka = stroka.toUpperCase();
console.log("В верхнем регистре = ", stroka);
stroka = stroka.toLowerCase();
console.log("В нижнем регистре = ", stroka);
stroka = stroka.replace(stroka, "К.А.Л")
console.log(stroka);
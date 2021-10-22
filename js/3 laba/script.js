"use strict";

function searchMax(a, b) {

}

let acc = [4];
acc[0] = 6 * Math.PI * Math.PI + 3 * Math.exp(8);
acc[1] = 2 * Math.cos(4) + Math.cos(12) + 8 * Math.exp(9);
acc[2] = 3 * Math.sin(9) + Math.log(5) + Math.sqrt(3);
acc[3] = 2 * Math.tan(5) + 6 * Math.PI + Math.sqrt(12);

// создать обьект состоящий из значения и номера, но не два разных а один, и его ...

let min = acc[0],
    max = acc[0];

for (let da of acc) {
    if (da < min) {
        min = da;
    }
    if (da > max) {
        max = da;
    }
    console.log(da);
}
console.log(min, max);
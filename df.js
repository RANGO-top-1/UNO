let A1 = +prompt("Введите A1");
let A2 = +prompt("Введите a2");
let A3 = +prompt("Введите a3");
let A4 = +prompt("Введите a4");
let A5 = +prompt("Введите a5");
let A6 = +prompt("Введите a5");

let r1 = mediana(A1, A2, A3, A4, A5, A6);
console.log(r1);

function mediana(x1, x2, x3, y1, y2, y3) {
    return 1 / 2 * (x1 - x2) * (y3 - y1) - (x3 - x1) * (y2 - y1);
};
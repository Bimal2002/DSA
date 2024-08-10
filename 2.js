function f(x) {
    x = "x-" + x;
    return function(y) {
        y = "y-" + x;
        return function(z) {
            return "z-" + y;
        }
    }
}

let g = f("a")("b")("c");
console.log(g); // Changed print to console.log

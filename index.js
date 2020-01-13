const express = require('express');
const child = require('child_process');
const app = express();
const port = 3000;
let response = 0;

app.use(express.static('public'));
const expressionCalc = child.spawnSync('bin/expression_calc_tree.exe', {
    stdio: [
        'pipe',
        'pipe',
        'pipe'
    ],
    input: "2 + 2",
    timeout: 20,
});

expressionCalc.stdout.on('data', (chunk) => {
    let test = chunk.toString();
    if (test !== "Enter an expression or enter QUIT: ")
    {
        response = test;
        console.log(test);
    }
});

app.get('/', (req, res) => {
    res.set('Content-Type', 'text/html');
    res.send(response);
});

app.listen(port, () => console.log(`Expression Calculator Back end listening on ${port}!`));
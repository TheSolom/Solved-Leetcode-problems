/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens) {
    const stack = []

    for (const token of tokens) {
        if (Number.isInteger(+token)) {
            stack.push(token)
        } else {
            const second = stack.pop()
            const first = stack.pop()

            const exp = `${first} ${token} ${second}`

            const res = Math.trunc(eval(exp))

            stack.push(res)
        }
    }

    return stack;
};
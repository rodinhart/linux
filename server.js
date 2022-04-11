const fs = require("fs")
const http = require("http")
const server = http.createServer((req, res) => {
  res.statusCode = 200
  if (req.url === "/add.c.wasm") {
    res.setHeader("content-type", "application/wasm")
    res.end(fs.readFileSync("./add.c.wasm"))
  } else {
    res.end(fs.readFileSync("./index.html"))
  }
})

server.listen(8080, "127.0.0.1", () => {
  console.log("Server running...")
})

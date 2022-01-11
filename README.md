The shadow-verify package exports a function that can be used to verify Linux
password hashes as used in the Linux /etc/shadow file.

Example
=======
```js
import shadowVerify from "shadow-verify";

if (shadowVerify(password, hash)) {
  console.log("password matched");
} else {
  console.error("password does not match");
}
```

Building User DB
================
Something like the following can be used to build a user DB with hashed
passwords from the shadow file.

```js
// returns object with username keys and password hash values
// call with "/etc/shadow" to import system users
function buildUserDB(file) {
  return readFileSync(file).split("\n").reduce((db, line) => {
    const [username, hash] = line.split(":");
    db[username] = hash;
  }, {});
}
```

import {createRequire} from "module";

if (process.platform !== "linux") {
  throw new Error("shadow password verification only supported on Linux");
}

// it appears addons can't be imported, so use legacy require to fetch addon
const require = createRequire(import.meta.url);
const {verify} = require("./build/Release/shadow.node");

export default verify;

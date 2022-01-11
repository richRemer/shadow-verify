import shadowVerify from "shadow-verify";
import expect from "expect.js";

describe("shadow-verify(string, string)", () => {
  const realValue = "foo";
  const badValue = "bar";
  const hash = "$6$V9txQQkn$widChfOgAdGU1dUPVctmdRlM1aAZolyoxS5JhoqMw0c4FjgXVyHmbSoNj4ku/uGxc/rnsyC55.nEBhzfT/HEe1";

  it("should test if second value is hash of first", () => {
    expect(shadowVerify(realValue, hash)).to.be(true);
    expect(shadowVerify(badValue, hash)).to.be(false);
  });
});

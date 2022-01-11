import shadowVerify from "shadow-verify";
import expect from "expect.js";

describe("shadow-verify(string, string)", () => {
  const realValue = "foo";
  const fakeValue = "bar";
  const hash = "$6$V9txQQkn$widChfOgAdGU1dUPVctmdRlM1aAZolyoxS5JhoqMw0c4FjgXVyHmbSoNj4ku/uGxc/rnsyC55.nEBhzfT/HEe1";

  it("should test if second value is hash of first", () => {
    expect(shadowVerify(realValue, hash)).to.be(true);
    expect(shadowVerify(fakeValue, hash)).to.be(false);
  });

  it("should throw if secret is missing or not a string", () => {
    expect(() => shadowVerify()).to.throwError();
    expect(() => shadowVerify(42, hash)).to.throwError();
  });

  it("should throw if hash is missing, is not a string, or is empty", () => {
    expect(() => shadowVerify(realValue)).to.throwError();
    expect(() => shadowVerify(realValue, 42)).to.throwError();
    expect(() => shadowVerify(realValue, "")).to.throwError();
  });
});

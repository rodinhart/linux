float add(float a, float b) {
  return a + b;
}

float sum(float xs[]) {
  return xs[0] + xs[1] + xs[2];
}

void draw(unsigned char *img, int W, int H) {
  double q = 4.0 / H;
  for (int sy = 0; sy < H; sy += 1 ) {
    double ry = -2.0 + q * sy;
    for (int sx = 0; sx < W; sx += 1) {
      double rx = -2.0 + q * sx;
      int n = 256;
      double a = rx, b = ry, c, d;
      do {
        c = a * a;
        d = b * b;
        b = 2 * a * b + ry;
        a = c - d + rx;
        n -= 1;
      } while (c + d < 4 && n > 0);

      int p = (sx + W * sy) * 4;
      img[p + 0] = n;
      img[p + 1] = n;
      img[p + 2] = n;
      img[p + 3] = 255;
    }
  }
}
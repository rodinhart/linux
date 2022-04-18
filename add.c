void draw(unsigned char *img, int W, int H) {
  double q = 0.05 / H;
  for (int sy = 0; sy < H; sy += 1 ) {
    double ry = 0.63 + q * sy;
    for (int sx = 0; sx < W; sx += 1) {
      double rx = 0.34 + q * sx;
      int n = 256;
      double a = rx, b = ry, c, d;
      do {
        c = a * a;
        d = b * b;
        b = 2 * a * b + ry;
        a = c - d + rx;
        n -= 1;
      } while (c + d < 4 && n > 0);

      int p = (sx + W * (H - 1 - sy)) * 4; // BGGRBRTT
      img[p + 0] = ((n & 7) | (n & 0x10) >> 1) * 17;
      img[p + 1] = ((n & 3) | (n & 0x60) >> 3) * 17;
      img[p + 2] = ((n & 3) | (n & 8) >> 1 | (n & 0x80) >> 4) * 17;
      img[p + 3] = 255;
    }
  }
}
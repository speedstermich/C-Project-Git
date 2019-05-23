#include <math.h>
#include <stdio.h>

int main() {
  int x1, y1, x2, y2, m1, n1, m2, n2; //定义点的坐标
  int lon, wid, s;                    //长,宽,面积
  int p, q, a, b, c, d, e, f, g, h;   //定义中间变量
  int tr1, tr2, tr3, tr4;             // 4种情况

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d %d %d", &m1, &n1, &m2, &n2);

  if ((x1 >= 0 || x2 >= 0 || y1 >= 0 || y2 >= 0 || m1 >= 0 || m2 >= 0 ||
       n1 >= 0 || n2 >= 0) &&
      (x1 <= 1000 || x2 <= 1000 || y1 <= 1000 || y2 <= 1000 || m1 <= 1000 ||
       m2 <= 1000 || n1 <= 1000 || n2 <= 1000)) {
    a = x2 - x1;
    b = y2 - y1;
    c = m2 - m1;
    d = n2 - n1;

    if ((fabs(c) > fabs(a)) && (fabs(b) < fabs(d))) {
      e = x1;
      f = x2;
      g = y1;
      h = y2;
      x1 = m1;
      x2 = m2;
      y1 = n1;
      y2 = n2;
      m1 = e;
      m2 = f;
      n1 = g;
      n2 = h;
    }

    tr1 = ((x1 < m1) && (m1 < x2) && (n1 > y1) && (n1 < y2));
    tr2 = ((x1 < m2) && (m2 < x2) && (n1 > y1) && (n1 < y2));
    tr3 = ((x1 < m1) && (m1 < x2) && (n2 > y1) && (n2 < y2));
    tr4 = ((x1 < m2) && (m2 < x2) && (n2 > y1) && (n2 < y2));

    if ((tr1 == 0) && (tr2 == 0) && (tr3 == 0) && (tr4 == 0)) {
      p = 0;
      q = 0;
    } else if ((tr1 != 0) && (tr2 != 0) && (tr3 != 0) && (tr4 != 0)) {
      p = n2 - n1;
      q = m2 - m1;
    } else if ((tr1 != 0) && (tr2 == 0) && (tr3 == 0) && (tr4 == 0)) {
      p = x2 - m1;
      q = y1 - n1;
    } else if ((tr1 == 0) && (tr2 != 0) && (tr3 == 0) && (tr4 == 0)) {
      p = x1 - m1;
      q = y1 - n1;
    } else if ((tr1 == 0) && (tr2 == 0) && (tr3 != 0) && (tr4 == 0)) {
      p = x2 - m1;
      q = y2 - n2;
    } else if ((tr1 == 0) && (tr2 == 0) && (tr3 == 0) && (tr4 != 0)) {
      p = x1 - m2;
      q = y2 - n2;
    } else if ((tr1 != 0) && (tr2 != 0) && (tr3 == 0) && (tr4 == 0)) {
      p = m2 - m1;
      q = n1 - y1;
    } else if ((tr1 != 0) && (tr2 == 0) && (tr3 != 0) && (tr4 == 0)) {
      p = n2 - n1;
      q = x2 - m1;
    } else if ((tr1 == 0) && (tr2 != 0) && (tr3 == 0) && (tr4 != 0)) {
      p = n2 - n1;
      q = x1 - m2;
    } else if ((tr1 == 0) && (tr2 == 0) && (tr3 != 0) && (tr4 != 0)) {
      p = m2 - m1;
      q = n2 - y2;
    } else
      printf("Error\n");

    lon = fabs(p);
    wid = fabs(q);
    s = lon * wid;

    printf("%d\n", s);
    return 0;
  }
}

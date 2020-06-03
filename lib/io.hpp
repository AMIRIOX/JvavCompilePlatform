//! io.hpp仍有问题,暂时不用,
//TODO 下个版本修复

// #include <bits/stdc++.h>
// namespace IO {
// const int str = 1 << 20;
// static char in_buf[str], *in_s, *in_t;
// bool __ = 0;
// char gc() {
//     return (in_s == in_t) &&
//                (in_t = (in_s = in_buf) + fread(in_buf, 1, str, stdin)),
//            in_s == in_t ? EOF : *in_s++;
// }
// void in(char &ch) {
//     if (__) return;
//     char c;
//     while ((c = gc()) != EOF && isspace(c))
//         ;
//     if (c == EOF)
//         __ = 1;
//     else
//         ch = c;
// }
// void in(char *ch) {
//     *ch = '\0';
//     if (__) return;
//     char c;
//     while ((c = gc()) != EOF && isspace(c))
//         ;
//     if (c == EOF) {
//         __ = 1;
//         return;
//     }
//     *ch = c;
//     ch++;
//     while ((c = gc()) != EOF && !isspace(c)) *ch = c, ch++;
//     if (c == EOF) __ = 1;
//     *ch = '\0';
// }
// template <typename T>
// void in(T &x) {
//     if (__) return;
//     char c = gc();
//     bool f = 0;
//     while (c != EOF && (c < '0' || c > '9')) f ^= (c == '-'), c = gc();
//     if (c == EOF) {
//         __ = 1;
//         return;
//     }
//     x = 0;
//     while (c != EOF && '0' <= c && c <= '9') x = x * 10 + c - 48, c = gc();
//     if (c == EOF) __ = 1;
//     if (f) x = -x;
// }
// template <typename T, typename... arr>
// void in(T &x, arr &... y) {
//     in(x), in(y...);
// }
// const char ln = '\n';
// static char out_buf[str], *out_s = out_buf, *out_t = out_buf + str;
// void flush() {
//     fwrite(out_buf, 1, out_s - out_buf, stdout);
//     out_s = out_buf;
// }
// void pt(char c) {
//     (out_s == out_t) ? (fwrite(out_s = out_buf, 1, str, stdout), *out_s++ = c)
//                      : (*out_s++ = c);
// }
// void out(const char *s) {
//     while (*s) pt(*s++);
// }
// void out(char *s) {
//     while (*s) pt(*s++);
// }
// void out(char c) { pt(c); }
// template <typename T>
// void out(T x) {
//     if (!x) {
//         pt('0');
//         return;
//     }
//     if (x < 0) pt('-'), x = -x;
//     char a[50], t = 0;
//     while (x) a[t++] = x % 10, x /= 10;
//     while (t--) pt(a[t] + '0');
// }
// template <typename T, typename... arr>
// void out(T x, arr &... y) {
//     out(x), out(y...);
// }
// }  // namespace IO
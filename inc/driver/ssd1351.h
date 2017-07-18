#ifndef SSD1351_H_
#define SSD1351_H_

enum ssd1351_scroll_direction {
    Left    = 0x01,
    Right   = 0x81
};

enum ssd1351_scroll_interval {
    Fast    = 0x00,
    Normal  = 0x01,
    Slow    = 0x02,
    Slowest = 0x03
};

extern void ssd1351_draw_point(unsigned char chXpos, unsigned char chYpos, unsigned int hwColor);
extern void ssd1351_draw_line(unsigned char chXpos0, unsigned char chYpos0, unsigned char chXpos1, unsigned char chYpos1, unsigned int hwColor);
extern void ssd1351_draw_h_line(unsigned char chXpos, unsigned char chYpos, unsigned char chWidth, unsigned int hwColor);
extern void ssd1351_draw_v_line(unsigned char chXpos, unsigned char chYpos, unsigned char chHeight, unsigned int hwColor);

extern void ssd1351_draw_column(unsigned char chXpos, unsigned char chYpos, unsigned char chHeight, unsigned int hwColor0, unsigned int hwColor1);

extern void ssd1351_draw_rect(unsigned char chXpos, unsigned char chYpos, unsigned char chWidth, unsigned char chHeight, unsigned int hwColor);
extern void ssd1351_draw_circle(unsigned char chXpos, unsigned char chYpos, unsigned char chRadius, unsigned int hwColor);

extern void ssd1351_draw_mono_bitmap(unsigned char chXpos, unsigned char chYpos, const unsigned char *pchBmp, unsigned char chWidth, unsigned char chHeight, unsigned int hwForeColor, unsigned int hwBackColor);
extern void ssd1351_draw_64k_bitmap(unsigned char chXpos, unsigned char chYpos, const unsigned char *pchBmp, unsigned char chWidth, unsigned char chHeight);

extern void ssd1351_fill_rect(unsigned char chXpos, unsigned char chYpos, unsigned char chWidth, unsigned char chHeight, unsigned int hwColor);
extern void ssd1351_fill_gram(unsigned int hwColor);

extern void ssd1351_clear_rect(unsigned char chXpos, unsigned char chYpos, unsigned char chWidth, unsigned char chHeight);
extern void ssd1351_clear_gram(void);

extern void ssd1351_display_char(unsigned char chXpos, unsigned char chYpos, unsigned char chChr, unsigned char chFontIndex, unsigned int hwForeColor, unsigned int hwBackColor);
extern void ssd1351_display_num(unsigned char chXpos, unsigned char chYpos, unsigned long chNum, unsigned char chLen, unsigned char chFontIndex, unsigned int hwForeColor, unsigned int hwBackColor);
extern void ssd1351_display_string(unsigned char chXpos, unsigned char chYpos, const char *pchString, unsigned char chFontIndex, unsigned int hwForeColor, unsigned int hwBackColor);

extern void ssd1351_horizontal_scrolling(unsigned char chYpos, unsigned char chHeight, unsigned char chDirection, unsigned char chInterval);
extern void ssd1351_deactivate_scrolling(void);

extern void ssd1351_show_checkerboard(void);
extern void ssd1351_show_rainbow(void);

extern void ssd1351_init(void);

#endif

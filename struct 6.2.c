/* makepoint函数：通过x，y坐标构造一个点 */
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}


/* addpoint function: add both of points */
struct point addpoint(struct point p1, struct point p2)\
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect function: if point p is in rectangle r, return 1, otherwise, return 0 */
int  ptinrect (struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

/***************************************************************************************/
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect function: standardized the matrix coordinates */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}



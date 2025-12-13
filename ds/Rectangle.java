
class Shape
{
    double width=1;
    public Shape()
    {
     
    }
    public Shape(double width)
    {
      this.width=width;
    }
      
}

public class Rectangle extends Shape {
    double height=1;
    public Rectangle()
    {
       super();
    }
    public Rectangle(double width,double height)
    {     super(width);    
        this.height=height;
}
  double get_area()
  {
    return height*width;
  }
  double getPerimeter()
  {
     return 2*(height+width);
  }
  void Display()
  {
     System.out.println("Rectangle Width "+width+" Height "+height+" Area "+get_area()+ " and  Perimeter "+getPerimeter());
  }

  public static void main(String[] args) {
    Rectangle r1=new Rectangle(5,10);
    r1.Display();
    Rectangle r2=new Rectangle(5.45405454,10.014564646);
    r2.Display();
  }
}



#include <STEPControl_Reader.hxx>
#include <StlAPI_Writer.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>
#include <Prs3d_Drawer.hxx>


int main()
{
    Standard_CString stpFileName = "/home/alex/Documents/STEP2STL/data/screw.step";
    Standard_CString stlFileName = "/home/alex/Documents/STEP2STL/data/screw.step.stl";

    STEPControl_Reader reader;    
    IFSelect_ReturnStatus status = reader.ReadFile(stpFileName);
    
    Standard_Integer nbRoots = reader.NbRootsForTransfer();
    Standard_Integer nbTrans = reader.TransferRoots();

    TopoDS_Shape shape = reader.OneShape();
    Handle(Prs3d_Drawer) aDrawer = new Prs3d_Drawer();

    Standard_Boolean result = StdPrs_ToolTriangulatedShape::Tessellate(shape, aDrawer);

    StlAPI_Writer writer;
    //writer.ASCIIMode() = Standard_False;
    writer.Write(shape, stlFileName);

    return 0;
}


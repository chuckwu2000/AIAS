/* 
    Eazy to find that when clk up, if a = 1, q = 4.
                                   if a = 0, q += 1 (but between 0~6)
 */
module top_module (
    input clk,
    input a,
    output [3:0] q );
    
    always @(posedge clk) begin
        if (a & 1) begin
            q = 4'b0100;
        end else begin
            q = q + 1;
            if(q == 4'b0111) begin
                q = 4'b0000;
            end
        end
    end

endmodule

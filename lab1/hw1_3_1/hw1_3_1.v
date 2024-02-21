/* 
    I can't find the relation between input & output, so just print 
    the waveform again.
 */
module top_module (
    input [2:0] a,
    output [15:0] q ); 
    
    always @(*) begin
        case(a)
            3'b000: begin
                q = 16'h1232;
            end
            3'b001: begin
                q = 16'haee0;
            end
            3'b010: begin
                q = 16'h27d4;
            end
            3'b011: begin
                q = 16'h5a0e;
            end
            3'b100: begin
                q = 16'h2066;
            end
            3'b101: begin
                q = 16'h64ce;
            end
            3'b110: begin
                q = 16'hc526;
            end
            3'b111: begin
                q = 16'h2f19;
            end
        endcase
    end        
endmodule

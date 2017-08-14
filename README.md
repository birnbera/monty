## 0x18. C - Stacks, Queues - LIFO, FIFO
  <h4 class="task">
    0. push, pall
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>push</code> and <code>pall</code> opcodes.</p>

<p><strong>Monty byte code files</strong></p>

<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

<p><strong>The monty program</strong></p>

<ul>
<li>Usage: <code>monty file</code></li>
<li>where <code>file</code> is the path to the file containing Monty byte code</li>
<li>If the user does not give any file or more than one argument to your program, print <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If, for any reason, it&#39;s not possible to use read the file, print <code>Error: Can&#39;t open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <code>&lt;file&gt;</code> is the name of the file</li>
</ul></li>
<li>If the file contains an invalid instruction, print <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number where the instruction appears. Line numbers always start at 1</li>
</ul></li>
<li>The monty program runs the bytecodes line by line and stop if:

<ul>
<li>it executed properly every line of the file</li>
<li>or it finds an error in the file</li>
<li>or an error occured</li>
</ul></li>
<li>If you can&#39;t malloc anymore, print <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>. You have to use <code>malloc</code> and <code>free</code> and are not allowed to use any other function from <code>man malloc</code></li>
</ul>

<p><strong>The push opcode</strong></p>

<p>The opcode <code>push</code> pushes an element to the stack.</p>

<ul>
<li>Usage: <code>push &lt;int&gt;</code></li>
<li>where <code>&lt;int&gt;</code> is an integer</li>
<li>if <code>&lt;int&gt;</code> is not an integer or if there is no argument to <code>push</code>, print the message <code>L&lt;line_number&gt;: usage: push integer</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number in the file</li>
</ul></li>
<li>You don&#39;t have to deal with overflows. Use the <code>atoi</code> function</li>
</ul>

<p><strong>The pall opcode</strong></p>

<p>The opcode <code>pall</code> prints all the values on the stack, starting from the top of the stack.</p>

<ul>
<li>Usage <code>pall</code></li>
<li>Format: see example</li>
<li>If the stack is empty, don&#39;t print anything</li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

  <h4 class="task">
    1. pint
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>pint</code> opcode.</p>

<p><strong>The pint opcode</strong></p>

<p>The opcode <code>pint</code> prints the value at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pint</code></li>
<li>If the stack is empty, print <code>L&lt;line_number&gt;: can&#39;t pint, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    2. pop
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>pop</code> opcode.</p>

<p><strong>The pop opcode</strong></p>

<p>The opcode <code>pop</code> removes the top element of the stack.</p>

<ul>
<li>Usage: <code>pop</code></li>
<li>if the stack is empty, print <code>L&lt;line_number&gt;: can&#39;t pop an empty stack</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    3. swap
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>swap</code> opcode.</p>

<p><strong>The swap opcode</strong></p>

<p>The opcode <code>swap</code> swaps the top two elements of the stack.</p>

<ul>
<li>Usage: <code>swap</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t swap, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    4. add
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>add</code> opcode.</p>

<p><strong>The add opcode</strong></p>

<p>The opcode <code>add</code> adds the top two elements of the stack.</p>

<ul>
<li>Usage: <code>add</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t add, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

  <h4 class="task">
    5. nop
      <span class="alert alert-warning mandatory-optional">
        mandatory
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>nop</code> opcode.</p>

<p><strong>The nop opcode</strong></p>

<p>The opcode <code>nop</code> doesn&#39;t do anything.</p>

<ul>
<li>Usage: <code>nop</code></li>
</ul>

  <h4 class="task">
    6. sub
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>sub</code> opcode.</p>

<p><strong>The sub opcode</strong></p>

<p>The opcode <code>sub</code> subtracts the top element of the stack from the second top element of the stack.</p>

<ul>
<li>Usage: <code>sub</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t sub, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/19.m 
7
2
1
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

  <h4 class="task">
    7. div
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>div</code> opcode.</p>

<p><strong>The div opcode</strong></p>

<p>The opcode <code>div</code> divides the second top element of the stack by the top element of the stack.</p>

<ul>
<li>Usage: <code>div</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t div, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
<li>If the top element of the stack is <code>0</code>, print <code>L&lt;line_number&gt;: division by zero</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

  <h4 class="task">
    8. mul
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>mul</code> opcode.</p>

<p><strong>The mul opcode</strong></p>

<p>The opcode <code>mul</code> multiplies the second top element of the stack with the top element of the stack.</p>

<ul>
<li>Usage: <code>mul</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t mul, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
</ul>

  <h4 class="task">
    9. mod
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>mod</code> opcode.</p>

<p><strong>The mod opcode</strong></p>

<p>The opcode <code>mod</code> computes the rest of the division of the second top element of the stack by the top element of the stack.</p>

<ul>
<li>Usage: <code>mod</code></li>
<li>If the stack is less than two element long, print <code>L&lt;line_number&gt;: can&#39;t mod, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>the top element of the stack contains the result</li>
<li>the stack is one element shorter</li>
</ul></li>
<li>If the top element of the stack is <code>0</code>, print <code>L&lt;line_number&gt;: division by zero</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

  <h4 class="task">
    10. comments
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Every good language comes with the capability of commenting. When the first non-space character of a line is <code>#</code>, treat this line as a comment (don&#39;t do anything).</p>

  <h4 class="task">
    11. pchar
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>pchar</code> opcode.</p>

<p><strong>The pchar opcode</strong></p>

<p>The opcode <code>pchar</code> prints the char at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pchar</code></li>
<li>The integer stored at the top of the stack is treated as the ascii value of the character to be printed</li>
<li>If the value is not in the ascii table (man ascii) print <code>L&lt;line_number&gt;: can&#39;t pchar, value out of range</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If the stack is empty, print <code>L&lt;line_number&gt;: can&#39;t pchar, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/28.m 
push 72
pchar
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/28.m 
H
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$
</code></pre>

  <h4 class="task">
    12. pstr
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>pstr</code> opcode.</p>

<p><strong>The pstr opcode</strong></p>

<p>The opcode <code>pstr</code> prints the string starting at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pstr</code></li>
<li>The integer stored in each element of the stack is treated as the ascii value of the character to be printed</li>
<li>The string stops where:

<ul>
<li>the stack is over</li>
<li>the value of the element is 0</li>
<li>the value of the element is not in the ascii table</li>
</ul></li>
<li>If the stack is empty, print only a new line</li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/31.m 
Holberton
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    13. rotl
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>rotl</code> opcode.</p>

<p><strong>The rotl opcode</strong></p>

<p>The opcode <code>rotl</code> rotates the stack to the top.</p>

<ul>
<li>Usage: <code>rotl</code></li>
<li>The top element of the stack becomes the last one, and the second top element of the stack becomes the first one</li>
<li><code>rotl</code> never fails</li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    14. rotr
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>rotr</code> opcode.</p>

<p><strong>The rotr opcode</strong></p>

<p>The opcode <code>rotr</code> rotates the stack to the bottom.</p>

<ul>
<li>Usage: <code>rotr</code></li>
<li>The last element of the stack becomes the top element of the stack</li>
<li><code>rotr</code> never fails</li>
</ul>

  <h4 class="task">
    15. stack, queue
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Implement the <code>stack</code> and <code>queue</code> opcodes.</p>

<p><strong>The stack opcode</strong></p>

<p>The opcode <code>stack</code> sets the format of the data to a stack (LIFO). This is the default behavior of the program.</p>

<ul>
<li>Usage: <code>stack</code></li>
</ul>

<p><strong>The queue opcode</strong></p>

<p>The opcode <code>queue</code> sets the format of the data to a queue (FIFO).</p>

<ul>
<li>Usage: <code>queue</code></li>
</ul>

<p>When switching mode:</p>

<ul>
<li>the top of the stack becomes the front of the queue</li>
<li>the front of the queue becomes the top of the stack</li>
</ul>

<pre><code>julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
julien@ubuntu:~/0x18. Stack (LIFO) &amp; queue (FIFO)$ 
</code></pre>

  <h4 class="task">
    16. Holberton
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Write a Brainf*ck script that prints <code>Holberton</code>, followed by a new line.</p>

<ul>
<li>All your Brainf*ck files should be stored inside the <code>brainfuck</code> sub directory</li>
<li>You can install the <code>bf</code> interpreter to test your code: <code>sudo apt-get install bf</code></li>
<li>Read: <a href="https://en.wikipedia.org/wiki/Brainfuck">Brainf*ck</a> </li>
</ul>

<pre><code>julien@ubuntu:~/brainfuck$ bf 1000-holberton.bf 
Holberton
julien@ubuntu:~/brainfuck$ 
</code></pre>

  <h4 class="task">
    17. Add two digits
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Add two digits given by the user.</p>

<ul>
<li>Read the two digits from stdin, add them, and print the result</li>
<li>The total of the two digits with be one digit-long (&lt;10)</li>
</ul>

<pre><code>julien@ubuntu:~/brainfuck$ bf ./1001-add.bf
81
9julien@ubuntu:~/brainfuck$
</code></pre>

  <h4 class="task">
    18. Multiplication
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Multiply two digits given by the user.</p>

<ul>
<li>Read the two digits from stdin, multiply them, and print the result</li>
<li>The result of the multiplication will be one digit-long (&lt;10)</li>
</ul>

<pre><code>julien@ubuntu:~/braifuck$ bf 1002-mul.bf
24
8julien@ubuntu:~/braifuck$
</code></pre>

  <h4 class="task">
    19. Multiplication level up
      <span class="alert alert-info mandatory-optional">
        #advanced
      </span>
  </h4>


  <!-- Progress vs Score -->

<!-- Task Body -->
  <p>Multiply two digits given by the user.<br />
<br />
<img src="http://mein-fun.com/data/media/5/brainfuck_bean.jpg" /><br />
<br /></p>

<ul>
<li>Read the two digits from stdin, multiply them, and print the result, followed by a new line</li>
</ul>

<pre><code>julien@ubuntu:~/brainfuck$ bf 1003-mul.bf 
77
49
julien@ubuntu:~/brainfuck$ 
</code></pre>

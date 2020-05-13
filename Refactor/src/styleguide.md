# Doxygen Style Guide

## Introduction
This document is a style guide to provide best practice formatting guidelines for ALEX Software Documentation using Doxygen. As such, the guide is a compilation of material from the [Doxygen Manual](http://www.doxygen.nl/manual/docblocks.html) and the [How to Write Doc Comments for the Javadoc Tool](https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html) technical article. The latter document contains a Javadoc style guide which provides conventions for creating useful API documents - these conventions are included at the end of this document as an essential documentation reference.

## Document Quick Links
1. [Setup for Documentation Commenting Using Doxygen](#doccommentsetup)
2. [Example of Documented Header File](#doccommentblock)
3. [Documenting a Class](#docclass)
3. [Documenting Enumerated Types](#docenum)
4. [Documenting A Function/Method](#docfunction)
5. [Additional (Useful) Special Commands](#docusefulcmds)
6. [Tables (Documenting Maps) - Markdown Support](#docmaps)
7. [Documenting Formuli - LaTeX Support](#docformulas)
8. [Tips From The Javadoc Style Guide](#javastyleguidetips)

## Setup for Documentation Commenting Using Doxygen {#doccommentsetup}

### Doxygen Configuration File
```c++
CPP_CLI_SUPPORT = YES //Parsing Support for C++/CLI language
JAVADOC_AUTOBRIEF = NO //Explicitly use \brief to specify a brief description
```
### VSCode
Install [Doxygen Document Generator](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen)

Using the default settings, *Doxygen Document Generator* automatically creates a doc comment block when you type `/**`

### Visual Studio
Using *Visual Studio Preview Version 16.6.0 Preview 5.0*

To switch to Doxygen, type “Doxygen” in the Ctrl+Q search box, or go to Tools > Options > Text Editor > C/C++ > > General, and choose your preferred documentation style: *Doxygen(/**)*

Source: [Doxygen and XML Doc Comment Support](https://devblogs.microsoft.com/cppblog/doxygen-and-xml-doc-comment-support/)

## Example of Documented Header File TODO{#doccommentblock} 
#### Doc Comment Block Prototype
Part-example of Documented Drive.h

## Documenting a Class TODO{#docclass} 

## Documenting A Function/Method {#docfunction}
### Function Special Commands

| Function Command | Decription | Doxygen Manual Link |
|----|----|----|
|`\param` | Used to describe a function parameter | [\param command](http://www.doxygen.nl/manual/commands.html#cmdparam) |
|`\return` | Used to describe the function return variable | [\return command](http://www.doxygen.nl/manual/commands.html#cmdreturn)
|`\sa` | Used to refer to associated functions, may be used to avoid unnecessary repitition | [\sa command](http://www.doxygen.nl/manual/commands.html#cmdsa)

The following tips (sourced from the [Javadoc Style Guide](https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html)) provide convention for using `\param` and `\return`:
*   `\param` - Use the command `\param` followed by the name (not the data type) of the parameter, then the description. By convention:
    * The first noun in the description is the data type of the parameter (may be preceded by an article "an", "a", "the"). Exception is the primitive type **int**
    * Parameter names are lowercase
*   `\return`
    *   **Omit** `\return`for methods that return void and for constructors
    *   **Include** `\return` for all other methods, even if its content is entirely redundant with the method description
        *   Having an explicit @return tag makes it easier for someone to find the return value quickly
        *   Whenever possible, supply return values for special cases (such as specifying the value returned when an out-of-bounds argument is supplied)

### Function Description Prototype
```c++
/**
 * \brief This is description which ends with a dot if *_AUTOBRIEF = YES
 *
 * This is a detailed description indicated by a space between a brief
 * and detailed description
 * \param a an integer
 * \return the result
 * \sa anotherFunction()
 */
 int testComment(int a);
```

## Documenting Enumerated Types {#docenum}
Source: [Doxygen Manual](http://www.doxygen.nl/manual/docblocks.html)

```c++
/**
 * An enum type.
 * The documentation block cannot be put after the enum! 
 */
 enum EnumType
 {
     int Eval1,     /**< enum value 1 */
     int Eval2,     /**< enum value 2 */
 };
```
[Doxygen Output - Documenting Enum Type](http://www.doxygen.nl/manual/examples/afterdoc/html/class_afterdoc___test.html)

**Using In-line Comments to Display an Enum Table**
`/**< enum value 1 */` represents an inline comment. This comment is placed after the member it refers to, this association is indicated by `<` symbol in the comment description. Here, the placement of in-line comments associated the enum variable `Eval1` with its `value 1` and Doxygen creates an enum table from these associations.


## Additional (Useful) Special Commands {#docusefulcmds}
| Function Command | Decription | Doxygen Manual Link |
|----|----|----|
|`\code` | Starts a code block. A code block is interpreted as source code. Names of class, members, and other documented entities are replaced by links to the documentation. Use with `\endcode` | [\code command](http://www.doxygen.nl/manual/commands.html#cmdcode) |
|`\b<word>` | Displays the argument \<word> in bold font. Equivalent to HTML `<b>multiple words</b>` | [\b command](http://www.doxygen.nl/manual/commands.html#cmdb) |
|`\e<word>` | Displays the argument \<word> in italic font. Equivalent to HTML `<em>multiple words</em>` | [\e command](http://www.doxygen.nl/manual/commands.html#cmde) |
|`\details` | Starts the detail description. Alternatively, a detailed description is started with a new paragraph (after a blank line) | [\detail command](http://www.doxygen.nl/manual/commands.html#cmddetails) |
|`\todo` | Starts a paragraph where a TODO item is described. The description will also add an item to a separate TODO list. | [\todo command](http://www.doxygen.nl/manual/commands.html#cmdtodo) |
|`\test` | Starts a paragraph where a test case can be described. The description will also add the test case to a separate test list. | [\test command](http://www.doxygen.nl/manual/commands.html#cmdtest) | 
|`\bug`|
|`\deprecated`|

## Tables (Documenting Maps) - Markdown Support {#docmaps}
Doxygen supports the use of Markdown to create tables in the doc comments. These should be used to document mappings (key-value pairs) when an enum type is not used.
See the example below:
```c++
/**
 * First Header | Second Header
 * ------------ | -------------
 * Content Cell | Content Cell
 * Content Cell | Content Cell
 */
 ```
 For column alignment, one or two colons (`:`) can be used to select the type of alignment in the header seperator line.
 See the example below:
 ```c++
 /**
  * | Right | Center | Left |
  * | ----: | :----: | :----|
  * | value | value  | value|
  */
```

## Documenting Formulas - LaTeX Support {#docformulas}

Doxygen supports the use of LaTeX commands to document formulas.
See the example below.
| Function Command | Decription | Doxygen Manual Link |
|----|----|----|
|`\f$` | Used to insert an in-line formula in a paragraph. End with `\f$` | [\f$ command](http://www.doxygen.nl/manual/commands.html#cmdfdollar)
| `f[ ... \f]` or `\f{ ... }{ ...\f}`| Used to insert column-centered and multi-line formulas into paragraph.

```c++
/**
 *  \f[
 *  \frac{1}{w_{new}} = \frac{1}{w_{1}} + \frac{1}{w_{2}}
 *  \f]
 
 * \f{eqnarray*}{
 *    w &=& \frac{\sigma L}{N_{gen} \epsilon_{trig}} \\
 *      &-& \sigma ...\ cross\ section \\
 *      &-& L ...\ luminosity \\
 *      &-& N_{gen}\ ... number\ of\ generated\ events \\
 *      &-& \epsilon_{trig}\ ...\ (known)\ trigger\ efficiency \\
 * \f}    
 */
```
Source: [ROOT Data Analysis Framework Style Guide](https://root.cern.ch/formatting-comments-doxygen)
## Tips From The Javadoc Style Guide {#javastyleguidetips}
Source: [Javadoc Style Guide](https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html)
The following tips from the Javadoc Style Guide are presented as either one-to-one translation from the guide (see source reference above) or a paraphrase of the original content.
1. **First Sentence** - The first sentence of each doc comment should be a summary sentence, containing a concise but complete description of the API item
2. **Comment Description** - Ideally, make it complete enough for conforming implementors. Realistically, include enough description so that someone reading the source code can write a substantial suite of conformance tests. Basically, the spec should be complete, including boundary conditions, parameter ranges and corner cases
3. **Use \<code> style for keywords and names**
4. **Use in-line links economically**
    * It is not necessary to add links for all API names in a doc comment. Add API links when:
        *   The user might actually want to click on it for more information
        *   It is the first occurrence of the API name in the doc comment
5. **Omit parentheses for the general form of methods and constructors** - only use when referring to the specific form (for example, when you wish to distinguish between two methods)
6. **OK to use phrases instead of complete sentences, in the interest of brevity**
7. **Use 3rd person (Descriptive) not 2nd person (prescriptive)** - Gets the label (preferred) over Get the label (avoid)
8. **Method descriptions begin with a verb phrase** - A method implements an operation, or performs an action, so it should begin with a verb phrase (for example, This method sends a position command to the `\code<Drive>` described by DriveID)
9. **Class/interface/field descriptions can omit the subject and simply state the object** - The aformentioned API often describe things rather than actions or behaviours, as such: *Drive class containing*... (preferred) over *This is a Drive class containing* (avoid)
10. **Use "this" instead of "the" when referring to an object created from the current class.** - Gets the toolkit for **this** component (preferred) over Gets the toolkit for **the** component (avoid)
11. **Add description beyond the API name** - The best API names are "self-documenting". Thus, it is not beneficial to simply repeat the API name in description. The ideal comment should reward the reader with additional information which is not immediately obvious from the API name.
    **Avoid** - The description below says nothing beyond what you know from reading the method name. The words "set", "tool", "tip", and "text" are simply repeated in the sentence
    ```java
    /**
     * Sets the tool tip text.
     * 
     * @param text the text of the tool tip
     */
     public void setToolTipText(String text)
    ```
    **Preferred** - This description more completely defines what a tool tip is, in the larger context of registering and being displayed in response to the cursor.
    
    ```java
    /**
     * Registers the text to display in a tool tup. The text
     * displays when the cursor lingers over the component.
     *
     * @param text  the string to display. If the text is null,
                    the tool tip is turned off for this component.
     */
     public void setToolTipText(String text)
    ```
12. **Tag Conventions** - **Note:** The equivalent Doxygen commands will be used in place of Javadoc commands (@ replaced by \\)
    Order of Tags - Include tags in the following order
    1.  `\author` (classes and interfaces only, required)
    2.  `\version` (classes and interfaces only, required)
    3.  `\param` (methods and constructors only)
    4.  `\return` (methods only)
    5.  `\exception`(`\throws` is a synonym)
    6.  `\sa` or `\see\`







